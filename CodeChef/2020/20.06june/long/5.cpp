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
#define dbg(x, y) cout << x << " = " << y << endl
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI &v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> &s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();


void dfs(int n, int a, int c, VVI &adj, vector<bool> &vis, map<int, VI> &mp){
	if(vis[a] > 0) return;
	vis[a] = c;
	mp[c].PB(a);
	for(unsigned int i=0; i<adj[a].size(); i++){
		dfs(n, adj[a][i], adj, vis);
	}
}

int cnt(int n, VVI &adj){
	vector<bool> vis(n+1, 0);
	int c = 1;
	map<int, VI> mp;
	for(int i=1; i<=n; i++){
		if(!vis[i]){
			dfs(n, i, c, adj, vis, mp);
			c++;
		}
	}
	c--;
	if(c == 1) return 0;
	
	VI freee;
	for(auto i: mp){
		set<int> st;
		for(int j: i.sec) st.insert(j);
		if(st.size() < i.sec.size()) freee.PB(i.sec.size() - st.size());
	}
	
	
	return c-1;
}


int main(){ 
    BoostIO;
    
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
   	    
   	    VVI adj(n+1);
        
        for(int i=0; i<m; i++){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
       
        cout << cnt(n, adj) << " " << 0 << endl;
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
