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
		int n, k; cin >> n >> k;
		vector<string> s(n+1);
		for(int i=1; i< n+1; i++){
			cin >> s[i];
		}
		vector<vector<pair<int, int>>> mat(n+1);
		for(int i=1; i<n+1; i++){
			for(int j=0; j<n; j++){
				if(s[j+1][i-1] == '1') mat[i].PB(MP(j+1,1));
			}
		}
		//for(int i=1; i<n+1; i++) print(mat[i]);
		int cnt=0;
		int idx = n;
		int step = 0;
		while(cnt<10000000){
			int loop =0;
			for(int i=0; i < mat[idx].size(); i++){
				cnt++;
				if(mat[idx][i].sec == 1){
					mat[idx][i].sec = 0;
					idx = mat[idx][i].fst;
					step++;
					break;
				}
				if(mat[idx][mat[idx].size()-1].sec == 0){
					idx = n;
					loop = 1;
					break;
				}
			}
		}
		if(cnt >=1000000 || loop = 1)
 	}
	return 0;
}
