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








int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		LL n, m, x, y;
		cin >> n >> m >> x >> y;

		LL sum = 0;
		VVI mat(n, VI (m, 0));

		LL mx = min(x, y);

		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(i == 0 && j == 0) mat[i][j] = mx;
				else if(i == 0){
					if(y >= x) mat[i][j] = min(x, y - mat[i][j-1]);
					else mat[i][j] = max((LL)0, y - mat[i][j-1]);
				}
				else if(j == 0){
					if(y >= x) mat[i][j] = min(x, y - mat[i-1][j]);
					else mat[i][j] = max((LL)0, y - mat[i-1][j]);
				}
				else{
					mat[i][j] = min(y - mat[i-1][j], y - mat[i][j-1]);
				}
				sum += mat[i][j];
			}
		}
		//print(mat);
		cout << sum << endl;

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
