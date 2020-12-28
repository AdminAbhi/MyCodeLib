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


bool kahns(VVI &adj, VI &ind, int n){
	VI res;
	priority_queue<int, VI, greater<int>> pq;
	for(int i=1; i<=n; i++){
		if(ind[i] == 0) pq.push(i);
	}
	while(!pq.empty()){
		int p = pq.top(); pq.pop();
		res.PB(p);
		for(int i: adj[p]){
			ind[i]--;
			if(ind[i] == 0) pq.push(i);
		}
	}
	//print(res);
	if(res.size() == n){
		for(int i: res) cout << i <<" ";
		return true;
	}
	return false;
}

int main() {
	BoostIO;
	int T = 1; 
	//cin >> T;
	while(T--){
		int n, m; cin >> n >> m;
		VVI adj(n+1);
		VI ind(n+1, 0);
		for(int i=0; i<m; i++){
			int u, v; cin >> u >> v;
			adj[u].PB(v);
			ind[v]++;
		}
		//print(ind);
		if(!kahns(adj, ind, n)) cout << "Sandro fails.";
	
	}
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
