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








int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		VVI adj(n+1);
		for(int i=0; i<n-1; i++){
			int u, v; cin >> u >> v;
			adj[u].PB(v);
			adj[v].PB(u);
		}
		string s; cin >> s;

		int r = 0, b = 0;
		for(char c: s){
			if(c == '0') r++;
			else b++;
		}

		queue<PI> que;
		que.push({1, 0});

		VVI level(n);
		vector<bool> vis(n+1,0);

		while(!que.empty()){
			PI p = que.front(); que.pop();

			if(vis[p.fst]) continue;
			vis[p.fst] = 1;

			level[p.sec].PB(p.fst);

			for(int i=0; i < adj[p.fst].size(); i++){
				if(!vis[adj[p.fst][i]]){
					que.push({adj[p.fst][i], p.sec + 1});
				}
			}

		}
		print(level);

		int odd = 0, even = 0;
		for(int i=0; i<level.size(); i++){
			if(i%2 == 0) even += level[i].size();
			else odd += level[i].size();
		}

		int cnt = 0;

		if(odd == r && even == b){
			VI diff(n,0);
			for(int i=0; i<level.size(); i++){
				for(int j=0; j<level[i].size(); j++){
					if(s[level[i][j]-1] - '0' == i%2) diff[i]++;
				}
			}
			cout << "1st" << endl;
			print(diff);

			for(int loop=0; loop<n; loop++){
				int temp = cnt;
				for(int i=1; i<n; i++){
					int mi = min(diff[i], diff[i-1]);
					cnt += mi;
					diff[i] -= mi;
					diff[i-1] -= mi;
				}
				if(temp == cnt) break;
			}
			cout << cnt << endl;
		}
		else if(odd == b && even == r){
			VI diff(n,0);
			for(int i=0; i<level.size(); i++){
				for(int j=0; j<level[i].size(); j++){
					if(s[level[i][j]-1] - '0' != i%2) diff[i]++;
				}
			}
			cout << "2st" << endl;
			print(diff);

			for(int loop=0; loop<n; loop++){
				int temp = cnt;
				for(int i=1; i<n; i++){
					int mi = min(diff[i], diff[i-1]);
					cnt += mi;
					diff[i] -= mi;
					diff[i-1] -= mi;
				}
				if(temp == cnt) break;
			}
			cout << cnt << endl;
		}
		else cout << -1 << endl;

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

