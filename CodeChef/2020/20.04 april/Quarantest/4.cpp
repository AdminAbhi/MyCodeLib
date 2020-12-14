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
inline void print(set<int> s){for(auto i:s) cout << i <<" "; cout << endl;}
inline void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<" ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();
 
int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
		int r, c; cin >> r >> c;
		int x, y; cin >> x >> y;

		int rmax = max(x, r - x - 1);
		int cmax = max(y, c - y - 1);

		cout << max(rmax, cmax) << endl;

		//int SE = r - x -1 + c - y -1;
		//int NE = x + c - y -1;
		//int NW = x + y;
		//int SW = r - x - 1 + y;
		
		
		//cout << max(max(SE, NE), max(NW, SW)) << endl;
	       
    }
	return 0;
}
