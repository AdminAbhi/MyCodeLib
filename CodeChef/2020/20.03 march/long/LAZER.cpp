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
	   VI arr(n);
	   for(int i=0; i<n; i++) cin >> arr[i]; 
		while(q--){
			int x1, x2, y; cin >> x1 >> x2 >> y;
			int coll = 0;
			if(x1 >= n){
				cout << coll << endl;
				continue;
			}
			for(int i=x1-1; i<x2-1; i++){
				if(arr[i] <= y && arr[i+1] >= y) coll++;
				else if(arr[i] >= y && arr[i+1] <= y) coll++;
			}
			cout << coll << endl;
		}
    }
	return 0;
}
