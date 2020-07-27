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

int main() {
	BoostIO;
	int T;  cin>>T;
	int t=1;
	while(t <= T){
		int n; cin >> n;
		VVI mat(n);
		LL sum = 0;
		for(int i=0; i<n; i++){
			mat[i].resize(n);
			for(int j=0; j<n; j++){
				cin >> mat[i][j];
				if(i==j) sum += mat[i][j];
			}
		}
		int r=0, c=0;
		for(int i=0; i<n; i++){
			set<int> row;
			set<int> col;
			for(int j=0; j<n; j++){
				row.insert(mat[i][j]);
				col.insert(mat[j][i]);
			}
			if(row.size() < n) r += 1;
			if(col.size() < n) c += 1;
		}
		
		cout << "Case #" << t << ": " << sum << " " << r << " " << c << endl;
		t++;
   }
	return 0;
}
