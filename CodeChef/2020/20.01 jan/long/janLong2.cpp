//@Abhi     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI > VVI;
typedef vector<VLL > VVLL;
typedef pair<int, int> PI;
typedef pair<LL, LL> PLL;
typedef vector<PI> VPI;
typedef vector<PLL> VPLL;

#define endl "\n"
#define PB push_back
#define MP make_pair
#define fst first
#define sec second
#define MOD7 1000000007
#define fn(i, n) for(int i = 0; i < (n); ++i)
#define fab(i, a, b) for(int i = (a); i < (b); ++i)
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VVLL v){ for(VLL i:v){ for(LL j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
	   int n,m; cin>>n>>m;
	   VVI arr(n);
	   for(int i=0; i<n; i++){
	       arr[i].resize(m);
	       for(int j=0; j<m; j++){
	           cin>>arr[i][j];
	       }
	   }
	   print(arr);
        if(n<3 || m<3){
            cout<<n*m<<endl;
            continue;
        }


    }
	return 0;
}
