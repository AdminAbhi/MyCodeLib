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



void dfs(VVI &adj, VI &vis, set<int> &res, VI &in, VI &low, int curr, int p, int &timer){
	vis[curr] = 1;
	in[curr] = low[curr] = timer++;
	int child_cnt = 0;
	for(int i: adj[curr]){
		if(i == p) continue;
		else if(vis[i] == 1){
			low[curr] = min(low[curr], in[i]);
		}
		else{
			dfs(adj, vis, res, in, low, i, curr, timer);
			low[curr] = min(low[curr], low[i]);
			child_cnt++;
			if(in[curr] <= low[i] && p != -1){
				res.insert(curr);
			}
		}
	}
	if(p == -1 && child_cnt > 1) res.insert(curr);
}


int main() {
	BoostIO;
	//int T; cin >> T;
	while(1){
		int n, m; cin >> n >> m;
		if(n == 0 && m == 0) break;
		VVI adj(n+1);
		for(int i=0; i<m; i++){
			int u, v; cin >> u >> v;
			adj[u].PB(v);
			adj[v].PB(u);
		}
		VI vis(n+1,0), in(n+1, -1), low(n+1, -1);
		set<int> res;
		int timer = 1;
		for(int i=1; i<=n; i++){
			if(vis[i] == 0) dfs(adj, vis, res, in, low, i, -1, timer);
		}
		
		
		cout << res.size() << endl;
	}
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
