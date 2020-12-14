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
	while(T--){
	   int n, q; cin >> n >> q;
	   
	   vector<VVI> mat(n+1);
	   
	   VI yy(n+1);
	   for(int i=1; i<=n; i++) cin >> yy[i];
	   
	   VI qres(q,0);
	   
	   for(int qq=0; qq<q; qq++){
			int x1, x2, y; cin >> x1 >> x2 >> y;
			
			for(int i=x1; i<x2; i++){
				VI box{qq, i+1 , y};
				int a = min(yy[i], yy[i+1]);
				int b = max(yy[i], yy[i+1]);
				if(y >= a && y <= b) mat[i].PB(box);
			}
				
		}
		for(int i=1; i<n; i++){
			int a = min(yy[i], yy[i+1]);
			int b = max(yy[i], yy[i+1]);
			
			for(unsigned int j=0; j<mat[i].size(); j++){
				if(mat[i][j][2] >= a && mat[i][j][2] <= b && mat[i][j][1] > i)
					qres[mat[i][j][0]]++;
			}
		}
		for(int i=1; i<=n; i++){
			cout << i << " --> ";
			for(unsigned int j=0; j<mat[i].size(); j++){
				cout << '{' << mat[i][j][0] << "," << mat[i][j][1] << "," << mat[i][j][2] << "}, ";
			}
			cout << endl;
		}
		//print(qres);
		for(int i:qres) cout << i << endl;
    }
	return 0;
}
