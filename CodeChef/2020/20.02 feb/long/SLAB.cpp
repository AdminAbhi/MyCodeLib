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
	   
		if(n > 250000 && n <= 500000){
			int tax = (n-250000)*0.05;
			n -= tax;
		}
		else if(n > 500000 && n <= 750000){
			int tax = 0; 
			tax += (500000 - 250000)*0.05;
			tax += (n - 500000)*0.10;
			n -= tax;
		}
		else if(n > 750000 && n <= 1000000){
			int tax = 0; 
			tax += (500000 - 250000)*0.05;
			tax += (750000 - 500000)*0.10;
			tax += (n - 750000)*0.15;
			n -= tax;
		}
		else if(n > 1000000 && n <= 1250000){
			int tax = 0; 
			tax += (500000 - 250000)*0.05;
			tax += (750000 - 500000)*0.10;
			tax += (1000000 - 750000)*0.15;
			tax += (n - 1000000)*0.20;
			n -= tax;
		}
		else if(n > 1250000 && n <= 1500000){
			int tax = 0; 
			tax += (500000 - 250000)*0.05;
			tax += (750000 - 500000)*0.10;
			tax += (1000000 - 750000)*0.15;
			tax += (1250000 - 1000000)*0.20;
			tax += (n - 1250000)*0.25;
			n -= tax;
		}
		else if(n > 1500000){
			int tax = 0; 
			tax += (500000 - 250000)*0.05;
			tax += (750000 - 500000)*0.10;
			tax += (1000000 - 750000)*0.15;
			tax += (1250000 - 1000000)*0.20;
			tax += (1500000 - 1250000)*0.25;
			tax += (n - 1500000)*0.30;
			n -= tax;
		}
	   cout<< n << endl;
    }
	return 0;
}
