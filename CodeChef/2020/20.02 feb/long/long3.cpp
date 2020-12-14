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
	LL tot=0;
	while(T--){
	   int n; cin>>n;
	   VVI mat(4);
	   for(int i=0; i<4; i++){
			VI v(4,0);
			mat[i] = v;
		}
		for(int i=0; i<n; i++){
			char c; cin>>c;
			int x; cin>>x;
			mat[c-'A'][(x-3)/3] += 1; 
		}
	   VI res(24,0);
	   int idx = 0;
	   for(int a=0; a<4; a++){
			for(int b=0; b<4; b++){
				if(b==a) continue;
				for(int c=0; c<4; c++){
					if(c==a || c==b) continue;
					for(int d=0; d<4; d++){
						if(d==a || d==b || d==c) continue;
						
						VI val(4);
						val[0] = mat[0][a];
						val[1] = mat[1][b];
						val[2] = mat[2][c];
						val[3] = mat[3][d];
						
						sort(val.begin(), val.end());
						
						LL cost=100;
						for(int i=3; i>=0; i--){
							if(val[i] !=0){
								res[idx] += cost*val[i];
								cost -= 25;
							}
							else res[idx] -= 100;
						}
						idx++;
					}
				}
			}
		}
		//print(res);
		sort(res.begin(), res.end());
		cout<<res[23]<<endl;
		tot += res[23];
    }
    cout<<tot<<endl;
	return 0;
}
