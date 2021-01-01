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



void fill(VLL &dp, VLL &arr, VLL &vis, int n, int l, int r){
	if(l > r){
		return;
	}
	else if(l == r){
		if(vis[l] == 0) dp[l] = arr[l];
		return;
	}
	else if(r - l == 1){
		if(vis[l] == 0 && vis[r] == 0){
			dp[l] = max(arr[l], arr[r]);
		}
		else if(vis[l] == 0){
			dp[l] = arr[l];
		}
		else{
			dp[l] = arr[r];
		}
		return;
	}
	
	LL l_max = max(arr[l] + arr[l+1], arr[l] + arr[r-1]);
	LL r_max = max(arr[r] + arr[r-1], arr[r] + arr[l+1]);
	
	if(arr[l+1] + arr[r-1] > max(l_max, r_max)){
		if(arr[l+1] > arr[r-1]){
			vis[l+1] = 1;
			dp[l] = arr[l+1];
		}
		else{
			vis[r-1] = 1;
			dp[l] = arr[r-1];
		}
	}
	else{
		if(vis[l] == 0 && vis[r] == 0){
			dp[l] = max(arr[l], arr[r]);
		}
		else if(vis[l] == 0){
			dp[l] = arr[l];
		}
		else{
			dp[l] = arr[r];
		}
		
	}
	fill(dp, arr, vis, n, l+1, r-1);
}




int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		LL n, x; cin >> n >> x;
		VLL arr(n); for(int i=0; i<n; i++) cin >> arr[i];
		
		VLL dp(n, 0), vis(n,0);
		
		fill(dp, arr, vis, n, 0, n-1);
		
		LL energy = 0;
		for(int i=0; i<n; i++){
			energy += dp[i];
		}
		//print(dp);
		
		if(energy >= x) cout << "YES" << endl;
		else cout << "NO" << endl;
		
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
