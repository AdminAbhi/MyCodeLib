// @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

#define dbg(x, y) cout << x << " = " << y << endl

inline void print(auto v){ for(auto i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();



bool cmp(PI a, PI b){
	return a.fst < b.fst;
}

bool isSorted(VI v){
	for(unsigned int i=0; i<v.size()-1; i++){
		if(v[i] > v[i+1]) return 0;
	}
	return 1;
}

void rightShift(int &a, int &b, int &c){
	swap(a, c);
	swap(b, c);
}

bool isit(int a, int b, int c){
	swap(a, c);
	swap(b, c);
	if(a < b && b < c) return true;
	return false;
}

int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		int n, k; cin >> n >> k;
		VI arr(n);
		for(int i=0; i<n; i++) cin >> arr[i];
		

		VI a(arr.begin(), arr.end());
		sort(a.begin(), a.end());

		//print(a);
		VI hash(n,0);
		
		map<int, int> mp;
		map<int, int> ma;
		
		for(int i=0; i<n; i++){
			mp[arr[i]] = i;
			if(arr[i] == a[i]) hash[i] = 1;
			ma[a[i]] = i;
		} 

		//print(hash);

		//cout << endl;
		//cout << "TRACE --- " << endl;
		VVI res;
		int size = 0;
		
		for(int i=0; i<n; ){

			while(i<n && hash[i]) i++;
			if(i >= n) break;
			
			VI idx(3);
			idx[0] = i;
			
			idx[1] = ma[arr[i]];

			int idx2 = ma[arr[idx[1]]];

			bool flag = 0;
			if(idx2 == idx[1] || idx2 == idx[0]){
				flag = 1;
				idx2 = i+1;
				while(idx2 < n && (hash[idx2] == 1 || idx2 == idx[1])){
					idx2++;
				}
				if(idx2 >= n) break;
			}
			idx[2] = idx2;

			/*
			int ii = i+1;
			int idx2 = mp[a[ii]];
			bool flag = 0;
		    while((ii < n-1) && (idx2 == idx[0] || idx2 == idx[1] || hash[idx2] == 1)){
				ii++;
				flag = 1;
		        idx2 = mp[a[ii]];
		    }
		    if(ii >= n) break;
		    else idx[2] = idx2;
			*/
			
			sort(idx.begin(), idx.end());
			int mini = min(arr[idx[0]], min(arr[idx[1]], arr[idx[2]]));
			int maxi = max(arr[idx[0]], max(arr[idx[1]], arr[idx[2]]));
			
			//cout << idx[0] << " " << idx[1] << " " << idx[2] << endl;
			//res.resize(size + 1);
			//res[size++] = { idx[0] +1, idx[1] +1,  idx[2]+1};

			if(flag){
				if(mp[a[idx[1]]] == idx[0]){
					rightShift(arr[idx[0]], arr[idx[1]], arr[idx[2]]);
					res.resize(size + 1);
					res[size++] = { idx[0] +1, idx[1] +1,  idx[2]+1};
				}
				else{
					rightShift(arr[idx[2]], arr[idx[1]], arr[idx[0]]);
					res.resize(size + 1);
					res[size++] = { idx[2] +1, idx[1] +1,  idx[0]+1};
				}
			}
			else if(arr[idx[0]] == maxi){
				rightShift(arr[idx[1]], arr[idx[0]], arr[idx[2]]);
				res.resize(size + 1);
				res[size++] = { idx[1] +1, idx[0] +1,  idx[2]+1};
			}
			else if(arr[idx[1]] == maxi){
				rightShift(arr[idx[0]], arr[idx[1]], arr[idx[2]]);
				res.resize(size + 1);
				res[size++] = { idx[0] +1, idx[1] +1,  idx[2]+1};
			}
			else break;
			
			mp[arr[idx[0]]] = idx[0];
			
			if(arr[idx[0]] == a[idx[0]]) hash[idx[0]] = 1;
			else hash[idx[0]] = 0;

			mp[arr[idx[1]]] = idx[1];

			if(arr[idx[1]] == a[idx[1]]) hash[idx[1]] = 1;
			else hash[idx[1]] = 0;
			
			mp[arr[idx[2]]] = idx[2];

			if(arr[idx[2]] == a[idx[2]]) hash[idx[2]] = 1;
			else hash[idx[2]] = 0;
			
			//print(arr);

			//print(hash);
			//cout << endl;

			
		}

		//print(arr);
		//cout << "-------" << endl;
		//print(res);

		//cout << "ANS ---- " << endl;
		
		if(!isSorted(arr)) cout << -1 << endl;
		else if(res.size() > k) cout << -1 << endl;
		else{
			cout << res.size() << endl;
			//print(res);
		}
    }
	return 0;
}

//    ##     ######   ##   ##  ####   #####   ##   ##     ##     ##   ##  ######   
//   ####    ##   ##  ##   ##   ##   ##   ##  ##   ##    ####    ##  ##   ##         
//  ##  ##   ##   ##  ##   ##   ##   ##       ##   ##   ##  ##   ## ##    ##         
// ##    ##  ######   #######   ##    #####   #######  ##    ##  ####     ######     
// ########  ##   ##  ##   ##   ##        ##  ##   ##  ########  ## ##    ##         
// ##    ##  ##   ##  ##   ##   ##   ##   ##  ##   ##  ##    ##  ##  ##   ##     
// ##    ##  ######   ##   ##  ####   #####   ##   ##  ##    ##  ##   ##  ######   
