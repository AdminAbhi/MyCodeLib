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
	   int n,k;
	   cin>>n>>k;
	   VLL arr(n);
	   for(int i=0; i<n; i++)	cin>>arr[i];
		VLL mod(n);
		for(int i=0; i<n; i++) mod[i] = arr[i]%k;
		//print(mod);
		VLL pre(n), post(n);
		pre[0] = mod[0];
		post[n-1] = k - mod[n-1];
		for(int i=1; i<n; i++){
			pre[i] = pre[i-1] + mod[i];
			post[n-i-1] = post[n-i] + k - mod[n-i-1];
 		}
 		//print(pre);
 		//print(post);
 		LL res = pre[n-1];
 		for(int i=0; i<n-1; i++){
			if(pre[i] >= post[i+1]){
				res = pre[i] - post[i+1];
				break;
			}
		}
		cout<<res<<endl;
    }
	return 0;
}
