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




void dfs(VVI &adj, int curr, int p, int depth, int &maxd, int &vtx){
	if(maxd < depth){
		maxd = depth;
		vtx = curr;
	}
	for(int i: adj[curr]){
		if(i != p) dfs(adj, i, curr, depth + 1, maxd, vtx);
	}
}


void dfs2(VVI &adj, int curr, int p, int cd, int &md){
	md = max(cd, md);
	for(int i: adj[curr]){
		if(i != p) dfs2(adj, i, curr, cd + 1, md);
	}
}

int main() {
	BoostIO;
	int n; cin >> n;
	VVI adj(n+1);
	for(int i=0; i<n-1; i++){
		int u, v; cin >> u >> v;
		adj[u].PB(v);
		adj[v].PB(u);
	}
	int md = 0, vtx = 1;
	dfs(adj, 1, -1, 0, md, vtx);
	int d = 0;
	dfs2(adj, vtx, -1, 0, d);
	
	cout << d;
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
