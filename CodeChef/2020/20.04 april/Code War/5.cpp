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
#define PB push_back
#define MP make_pair
#define fst first
#define sec second
#define MOD7 1000000007
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

#define lim 500000

int main() {
	BoostIO;
	int m, n, u, q; cin >> m >> n >> u >> q;

	VVI hash(m+1, VI (n+1, 0));
	VVI mat(m, VI (n));

	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}

	while(u--){
		int k, r1, c1, r2, c2;
		cin >> k >> r1 >> c1 >> r2 >> c2;

		hash[r1][c1] += k;
		hash[r2+1][c2] -= k;
		hash[r2][c2+1] -= k;
	}

	
	
	for(int i=1; i<=m; i++){
		for(int j=1; j<=n; j++){
			hash[i][j] += hash[i][j-1];
		}
	}
	for(int j=1; j<=n; j++){
		for(int i=1; i<=m; i++){
			hash[i][j] += hash[i-1][j];
		}
	}

	print(hash);

	while(q--){
		int r1, r2, c1, c2;
		cin >> r1 >> c1 >> r2 >> c2;
	}
	
	return 0;
}
