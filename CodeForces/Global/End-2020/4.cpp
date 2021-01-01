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





int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		VVI adj(n+1);
		VLL wt(n+1);
		LL tot = 0;
		for(int i=1; i<=n; i++){
			cin >> wt[i];
			tot += wt[i];
		} 
		
		//VI in(n+1, 0), out(n+1, 0);
		
		VI deg(n+1, 0);
		
		int q = n-1;
		
		while(q--){
			int u, v; cin >> u >> v;
			adj[u].PB(v);
			adj[v].PB(u);
			deg[u]++;
			deg[v]++;
		}
		
		priority_queue<pair<pair<LL, int>, int>> pq;
		
		VI vis(n+1, 0);
		
		for(int i=1; i<=n; i++){
			if(deg[i] == 1){
				int max_j = adj[i][0];
				LL max_w = wt[adj[i][0]];
				pq.push({{max_w, max_j}, i});
			} 
		}
		
		VLL res; res.PB(tot);
		
		while(!pq.empty()){
			auto p = pq.top(); pq.pop();
			vis[p.sec] = 1;
			tot += p.fst.fst;
			res.PB(tot);
			deg[p.fst.sec] -= 1;
			if(deg[p.fst.sec] == 1){
				int max_j = -1;
				LL max_w = -1;
				for(int j: adj[p.fst.sec]){
					if(vis[j] == 0){
						max_w = wt[j];
						max_j = j;
						break;
					}
				}
				pq.push({{max_w, max_j}, p.fst.sec});
			}
		}
		for(int i=0; i<n-1; i++) cout << res[i] << " ";
		cout << endl;
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
