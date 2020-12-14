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
	   int n,p; 
	   cin>>n>>p;
	   
	   VI coin(n);
	   for(int i=0; i<n; i++) cin>>coin[i];
		
		LL sum=0;
		VI res(n,0);
		int i=n-1;
		int pp = p;
		bool flag = 0;
		
		while(sum <= p && i >= 0){
			if(i==0 && pp % coin[i] == 0){
				flag = 1;
				break;
			}
			else if(coin[i] > pp){
				res[i]++;
				break;
			}
			else if(pp % coin[i] == 0){
				res[i] = pp/coin[i] - 1;
			}
			else{
				res[i] = pp/coin[i] + 1;
			}
			sum += res[i]*coin[i];
			pp -= res[i]*coin[i];
			i--;
		}
		if(flag) cout<<"NO\n";
		else {
			cout << "YES ";
			print(res); 
		}
		
	}
	return 0;
}
