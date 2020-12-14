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
	   int a=0, b=0;
	   int res = -1;
		for(int i=0; i<2*n; i++){
 		
 			if(i%2 == 0 && s[i] == '1') a++;
			else if(i%2 != 0 && s[i] == '1') b++;
			
			if(i==2*n-1){
				res = 2*n;
				break;
			} 
			
			if(a > b + (2*n -i)/2){
				res = i+1;
				break;
			}
			else if(b > a + (2*n -i)/2){
				res = i+1;
				break;
			}
		}
		
		cout << res << endl;
    }
	return 0;
}
