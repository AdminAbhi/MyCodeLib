//=============================================================================
// @abhi_admin     linkedin.com/in/adminabhi     Email: abhiavisekkr@gmail.com
//=============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define endl "\n"
#define fst first
#define sec second
#define PB push_back
#define MP make_pair
#define MOD7 1000000007
#define uset unordered_set
#define umap unordered_map
#define BoostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl;}
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl;}
inline void print(VVI &v){ for(VI i:v) print(i);}
inline void print(PI p){ cout<<"("<<p.fst<<":"<<p.sec<<"), ";}
inline void print(VPI &P){for(PI i:P) print(i); cout<<endl;}
inline void print(set<int> &s){for(int i:s)cout<<i<<" "; cout<<endl;}
inline void print(map<int,int> &m){for(auto i:m) print(i); cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

LL power(LL a, LL b, LL MOD){
    LL res = 1;
    while(b){
        if(b%2) res = (res*a) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }return res;
}
LL iMOD(LL a, LL p){
    return power(a, p-2, p);
}
//=============================================================================
//--------------------------Keep-Calm-and-Code---------------------------------
//=============================================================================


VLL maxSum(VLL &a, VI &hash, LL k){
	LL n = a.size();
	vector<vector<bool>> mat(n, vector<bool>(2*k+1));
	for(int i=0; i<n; i++){
		for(int j=0; j<=k; j++){
			if(j==0) mat[i][j] = true;
			else if(i == 0){
				if(j == a[i]) mat[i][j] = true;
				else mat[i][j] = false;
			}
			else if(j < a[i]){
				mat[i][j] = mat[i-1][j];
			}
			else if(j == a[i]){
				mat[i][j] = true;
			}
			else{
				mat[i][j] = mat[i-1][j] || mat[i-1][j - a[i]];
			}
		}
	}
	/*
	cout << "n = " << n << ", k = " << k << endl;
	for(auto i: mat){
		for(auto j: i) cout << j << " ";
		cout << endl;
	}
	*/
	int i = k;
	for( ; i>=0; i--){
		if(mat[n-1][i]) break;
	} 
	int j = i;
	i = n-1;
	VLL res;
	
	LL sum = 0;
	while(i > 0 && j >= 0){
		if(i > 0 && j - a[i] >= 0){
			if(mat[i-1][j - a[i]]){
				res.PB(a[i]);
				j -= a[i];
				sum += a[i];
			}
		}
		else if(i == 0 && j != 0){
			if(a[i] == j) res.PB(a[i]), sum += a[i];
		}
		i--;
	}
	if(sum == k) return res;
	
	for(int i: res){
		hash[i]--;
	}
	for(int i=0; i<a.size(); i++){
		if(hash[a[i]] && sum + hash[a[i]] >= k){
			res.PB(i);
			hash[a[i]]--;
			break;
		}
	}
	return res;
}

/*
VLL maxSum2(VLL &arr, int k){
	LL tot = 0;
	VLL res;
	for(int i=0; i<arr.size(); i++){
		if(tot < k){
			tot += arr[i];
			res.PB(arr[i]);
		}
		else break;
	}
	return res;
}
*/

VLL maxSum2(VLL &arr, VI &hash, int k){
	LL tot = 0;
	VLL res;
	for(int i=0; i<arr.size(); i++){
		if(tot + arr[i] <= k){
			tot += arr[i];
			res.PB(arr[i]);
			hash[arr[i]]--;
		}
	}
	if(tot < k){
		for(int i=arr.size()-1; i>=0; i--){
			if(hash[arr[i]] && tot + arr[i] >= k){
				res.PB(arr[i]);
				hash[arr[i]]--;
				tot += arr[i];
				break;
			}
		}
	}
	return res;
}

void sol(){
	LL n, k; cin >> n >> k;
	VLL arr(n); LL sum = 0;
	for(int i=0; i<n; i++){
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum < 2*k){
		cout << -1 << endl;
		return;
	}
	
	int MAX = 100000;
	VI hash(MAX+1, 0);
	for(int i=0; i<n; i++){
		hash[arr[i]]++;
	}
	
	sort(arr.begin(), arr.end());
	VLL min_MAX1 = maxSum(arr, hash, k);
	
	sort(arr.rbegin(), arr.rend());
	VLL min_MAX2 = maxSum2(arr, hash, k);

	VI sec_set;
	LL tot = 0;
	
	if(min_MAX1.size() < min_MAX2.size()){
		LL ss = 0; for(LL i: min_MAX1) ss += i;
		for(int i=0; i<n; i++){
			if(hash[arr[i]] && tot + arr[i] < k){
				sec_set.PB(arr[i]);
				hash[arr[i]]--;
				tot += arr[i];
			}
			else if(tot >= k) break;
		}
		if(ss >=k && tot >= k) cout << min_MAX1.size() + sec_set.size() << endl;
		else cout << -1 << endl;
	}
	else{
		LL ss = 0; for(LL i: min_MAX2) ss += i;
		for(int i=0; i<n; i++){
			if(hash[arr[i]] && tot + arr[i] < k){
				sec_set.PB(arr[i]);
				hash[arr[i]]--;
				tot += arr[i];
			}
			else if(tot >= k) break;
		}
		if(ss >=k && tot >= k) cout << min_MAX1.size() + sec_set.size() << endl;
		else cout << -1 << endl;
	}

}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		sol();
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
