//=============================================================================
// @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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
inline void print(map<int,int> m){for(auto i:m) print(i); cout<<endl;}

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



void dfs(int &cnt, VVI &adj, int v){
	cnt++;
	for(int i=0; i<adj[v].size(); i++){
		dfs(cnt, adj, adj[v][i]);
	}
}

void dfs3(VVI &adj, VI &vis, int v){
	if(vis[v]) return;
	vis[v] = 1;
	for(int i=0; i<adj[v].size(); i++){
		dfs3(adj, vis, adj[v][i]);
	}
}

void dfs2(int &change, VVI &adj, VVI &adj2, map<int, VI> &mp, int p, int v){

	for(int i=0; i<adj2[v].size(); i++){
		if(adj2[v][i] != p){
			bool foo = 1;
			for(int j=0; j<adj[v].size(); j++){
				if(adj2[v][i] == adj[v][j]){
					foo = 0;
					break;
				}
			}
			if(foo) change++;
			dfs2(change, adj, adj2, mp, v, adj2[v][i]);
		}
	}
}


int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		VVI adj(n+1);
		VVI adj2(n+1);
		map<int, VI> mp;

		for(int i=0; i<n-1; i++){
			int u, v; cin >> u >> v;
			adj[u].PB(v);
			mp[u].PB(v);

			adj2[u].PB(v);
			adj2[v].PB(u);
		}

		int res = n-1;
		int root;
		for(int i=1; i<=n; i++){
			int cnt = -1;

			dfs(cnt, adj, i);
			//cout << cnt << endl;

			if(res > n-1 - cnt){
				res = n-1 - cnt;
				root = i;
			}
		}
		//cout << res << endl;

		int change = 0;

		dfs2(change, adj, adj2, mp, -1, root);

		//cout << change << endl;

		int rest = n;
		VI vis(n+1, 0);

		int ans = 0;

		for(int i=1; i<=n; i++){
			if(vis[i] == 0){
				dfs3(adj, vis, i);
				ans++;
			}
		}
		cout << min(ans - 1, change) << endl;

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

