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


bool cmp(pair<int, VI> &a, pair<int, VI> &b){
	if(a.fst > b.fst) return true;
	else if(a.fst < b.fst) return false;
	else return a.sec.size() <= b.sec.size();
}


void dfs(VI &arr, VI &vis, VVI &adj, int i, int &tot, VI &mem){
	vis[i] = 1;
	mem.PB(i+1);
	tot += arr[i];
	for(int j: adj[i]){
		if(vis[j]) continue;
		dfs(arr, vis, adj, j, tot, mem);
	}
}


int main() {
	BoostIO;
	int n; cin >> n;
	VI arr(n); for(int i=0; i<n; i++) cin >> arr[i];
	VVI adj(n+1);
	int m; cin >> m;
	while(m--){
		int u, v; cin >> u >> v;
		adj[u-1].PB(v-1);
		adj[v-1].PB(u-1);
	}
	VI vis(n+1, 0);
	vector<pair<int, vector<int>>> res;
	//int MAX = -1;
	for(int i=0; i<n; i++){
		if(vis[i]) continue;
		int tot = 0;
		VI mem;
		dfs(arr, vis, adj, i, tot, mem);
		res.PB({tot, mem});
	}
	sort(res.begin(), res.end(), cmp);
	sort(res[0].sec.begin(), res[0].sec.end());
	print(res[0].sec);
	
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
