//@Abhi     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
	   int n; cin>>n;
	   string s; cin>>s;
	   VI aa, bb;
	   int res = -1;
		for(int i=0; i<2*n; i++){
			if(i%2 == 0 && s[i] == '1') aa.PB(1);
			else if(i%2 == 0 && s[i] == '0')	aa.PB(0);
			else if(i%2 != 0 && s[i] == '1') bb.PB(1);
			else if(i%2 != 0 && s[i] == '0')	bb.PB(0);
		}
		int a=0, b=0;
		for(int i=0; i<n; i++){
			if(aa[i] == 1) a++;
			if(bb[i] == 1) b++;
		
			if(i==n-1){
				res = 2*n;
			}
			if(abs(a-b) > n-i-1){
				res = 2*(i+1);
				break;
			}
		}
		//print(aa);
		//print(bb);
		
		
		cout << res << endl;
    }
	return 0;
}
