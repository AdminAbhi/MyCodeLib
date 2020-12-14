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
	   LL n, a, b, c;
	   cin >> n >> a >> b >> c;
	   VLL floor(n);
	   bool temp = 0;
	   for(int i=0; i<n; i++){
			cin >> floor[i];
			if((floor[i] >= a && floor[i] <= b) || (floor[i] >= b && floor[i] <= a))
			temp = 1;
		} 
	   sort(floor.begin(), floor.end());
	   if(temp){
			cout << abs(a-b) + c <<endl;
		}
		else{
			if(floor[0] > max(a,b)){
				LL tt = floor[0] + c + floor[0] - a - b;
				cout<< tt <<endl;
			}
			else{
				LL tt = a + b + c - floor[n-1] - floor[n-1];
				cout<< tt <<endl;
			}
		}
	}
	return 0;
}
