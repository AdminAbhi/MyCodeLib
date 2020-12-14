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

#define MOD 998244353

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
		int n, sum; cin >> n >> sum;
		sum = 100 - sum;
		VI p(n), t(n);
	    for(int i=0; i<n; i++) cin >> p[i];
	    for(int i=0; i<n; i++) cin >> t[i];

		int d = INT_MAX;
		int f = INT_MAX;
		
	    for(int i=0; i<n; i++){
			if(t[i] == 0){
				d = min(d, p[i]);
			}
			else{
				f = min(f, p[i]);
			}
		}
		if(d == INT_MAX || f == INT_MAX){
			cout << "no" << endl;
			continue;
		}
		if(d + f <= sum) cout << "yes" << endl;
		else cout << "no" << endl;
    }
	return 0;
}
