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
	VLL po2(60);
	po2[0]=1;
	for(LL i=1; i<60; i++){
		po2[i] = po2[i-1] * 2; 
	}
	//print(po2);
	while(T--){
		LL l, r;
		cin >> l >> r;
		int max = log2(r) +1;
		VI arr(max, 0);
		for(int i=0; i<max; i++){
			int cnt = 0;
			if(l & po2[i]){
				int n = (r-l+1) < po2[i] + 1 ? (r-l+1) : po2[i] + 1; 
				cnt = n - (l - po2[(int)log2(l)] -1 );
			}
			arr[i] = cnt;
		}
		LL sum = 0;
		for(int i=0; i<max; i++){
			if(arr[i] > 0){
				sum += (arr[i]*po2[i]) % MOD7;
			}
		}
		print(arr);
		cout<<sum<<endl;
	}
	return 0;
}
