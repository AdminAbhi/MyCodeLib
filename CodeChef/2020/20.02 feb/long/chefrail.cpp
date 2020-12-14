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
	   int n,m;
	   cin >> n >> m;
	   
	   VLL x(n), y(m);
	   VI xph(100001,0), xnh(100001,0), yph(100001,0), ynh(100001,0);
	   
	   bool zero1 = 0;
	   for(int i=0; i<n; i++){
			cin >> x[i];
			if(x[i] == 0) zero1 = 1;
			if(x[i] >= 0) xph[x[i]] = 1;
			else xnh[abs(x[i])] = 1;
		}
		bool zero2 = 0;
		for(int i=0; i<m; i++){
			cin >> y[i];
			if(y[i] == 0) zero2 = 1;
			if(y[i] >= 0) yph[y[i]] = 1;
			else ynh[abs(y[i])] = 1;
		}
	   sort(x.begin(), x.end());
	   sort(y.begin(), y.end());
	   
	   //print(x);
	   //print(y);
	   
	   int midx;
	   for(int i=0; i<n; i++){
			if(x[i] > 0){
				midx = i;
				break;
			}
		}
		
	   LL cnt=0;
	   for(int i=0; i<n; i++){
			if(x[i] >= 0) break;
			for(int j=midx; j<n; j++){
				//if(x[j] <= 0) continue;
				double c = sqrt(abs(x[i]*x[j]));
				if(c - floor(c) == 0){
					if(yph[c] == 1) cnt++;
					if(ynh[c] == 1) cnt++;
				}
			}
		}
		
		int midy;
	   for(int i=0; i<m; i++){
			if(y[i] > 0){
				midy = i;
				break;
			}
		}
		
		for(int i=0; i<m; i++){
			if(y[i] >= 0) break;
			for(int j=midy; j<m; j++){
				//if(y[j] <= 0) continue;
				double c = sqrt(abs(y[i]*y[j]));
				if(c - floor(c) == 0){
					if(xph[c] == 1) cnt++;
					if(xnh[c] == 1) cnt++;
				}
				
			}
		}
		if(zero1 && zero2){
			cnt += (n-1)*(m-1);
		}
		else if(zero1){
			cnt += (n-1)*m;
		}
		else if(zero2){
			cnt += (m-1)*n;
		}
		
	   cout << cnt << endl;
    }
	return 0;
}
