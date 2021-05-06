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


bool dfs(VVI &mat, int n, int m, int i, int j, int k){
	if(i < 1 || i > n || j < 1 || j > m) return false;
	if(k < 0) return false;
	if(k == 0 && i == n && j == m) return true;
	if(mat[i-1][j-1]) return false;
	
	//print(mat);
	//cout << endl;
	
	mat[i-1][j-1] = 1;
	
	if(dfs(mat, n, m, i+1, j, k-j)) return true;
	if(dfs(mat, n, m, i, j+1, k-i)) return true;
	 
	mat[i-1][j-1] = 0;
	return false;
}


void sol(){
	int n, m, k; cin >> n >> m >> k;
	if(min(n, m) == 1){
		if(max(n,m)-1 == k) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if(m-1 + m*(n-1) == k) cout << "YES" << endl;
	else cout << "NO" << endl;
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
