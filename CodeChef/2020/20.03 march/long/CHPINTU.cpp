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
		int n,m; cin >> n >> m;
		VI type(n), bask(m,0), check(m,0);
		for(int i=0; i<n; i++){
			cin >> type[i];
			check[type[i]-1] = 1;
		}
		for(int i=0; i<n; i++){
			int x; cin >> x;
			bask[type[i]-1] += x;
		}
		print(bask);
		int min = INT_MAX;
		for(int i=0; i<m; i++){
			if(check[i]==0) continue;
			if(bask[i] < min)  min = bask[i];
		}
	   cout << min << endl;
    }
	return 0;
}
