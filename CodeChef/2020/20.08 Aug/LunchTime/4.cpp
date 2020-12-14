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
		int n, m; cin >> n >> m;
		VVI rat(m+1, VI (n)); for(int i=0; i<n; i++) cin >> rat[0][i];

		VI maxRat(n, INT_MIN);
		VI bratM(n);

		for(int j=0; j<n; j++){
			for(int i=1; i<=m; i++){
				cin >> rat[i][j];
				rat[i][j] += rat[i-1][j];

				if(maxRat[j] < rat[i][j]){
					maxRat[j] = rat[i][j];
					bratM[j] = i;
				}
			}
		}
		//print(rat);
		//cout << "-----\n";

		VVI rank(m+1, VI (n));

		for(int i=1; i<=m; i++){
			VI ran(n);
			map<int, VI> mp;
			for(int j=0; j<n; j++){
				ran[j] = rat[i][j];
				mp[ran[j]].PB(j);
			}
			sort(ran.rbegin(), ran.rend());
			int r = 1;
			for(int idx: mp[ran[0]])
				rank[i][idx] = 1;

			for(int ii=1; ii<n; ii++){
				if(ran[ii] < ran[ii-1]){
					r = ii+1;
					for(int idx: mp[ran[ii]])
						rank[i][idx] = r;
				}
				else{
					for(int idx: mp[ran[ii]])
						rank[i][idx] = r;
				}
			}
		}
		VI brank(n, INT_MAX);
		VI brM(n);

		for(int i=0; i<n; i++){
			for(int j=1; j<=m; j++){
				if(brank[i] > rank[j][i]){
					brank[i] = rank[j][i];
					brM[i] = j;
				}
			}
		}
		int ans = n;
		for(int i=0; i<n; i++){
			if(brM[i] == bratM[i]) ans--;
		}

		//print(rank);

		cout << ans << endl;
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

