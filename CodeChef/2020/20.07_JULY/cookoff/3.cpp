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

//=============================================================================
//--------------------------Keep-Calm-and-Code---------------------------------
//=============================================================================



void dfs(vector<VLL> &adj, vector<VLL> &wt, stack<LL> &st, VI &hash, int v){
	if(hash[v] == 1) return;

	hash[v] = 1;
	st.push(v);

	wt[v].PB(st.size());

	for(int i=0; i<adj[v].size(); i++){
		dfs(adj, wt, st, hash, adj[v][i]);
	}

	//cout << "000" << endl;
	st.pop();
	hash[v] = 0;
}




int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		vector<VLL> adj(n+1);
		for(int i=0; i<n-1; i++){
			int u, v; cin >> u >> v;
			adj[u].PB(v);
			adj[v].PB(u);
		}

		VI left;
		for(int i=1; i<adj.size(); i++) if(adj[i].size() == 1) left.PB(i);

		vector<VLL> wt(n+1);

		while(left.size()){
			VI hash(n+1, 0);
			stack<LL> st;

			dfs(adj, wt, st, hash, left.back());

			left.pop_back();
		}

		for(int i=1; i<=n; i++){
			//print(wt[i]);
			LL lcm = 1;
			for(int j=0; j<wt[i].size(); j++){
				lcm = (lcm * wt[i][j])/ __gcd(lcm, wt[i][j]);
			}
			cout << lcm << " ";
		}
		cout << endl;

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
