// @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

int main() {
	BoostIO;
	int T, S;  cin >> T >> S;
	while(T--){
		if(S == 1){
			int n; cin >> n;
			VI a(n),b(n);
			map <int, int> mp;
			for(int i=0; i<n; i++) cin >> a[i];
			for(int i=0; i<n; i++) cin >> b[i];
		
			sort(a.begin(), a.end());
			sort(b.begin(), b.end());
			
			bool check = 1;
			for(int i=0; i<n; i++){
				if(a[i] >= b[i]){
					check = 0;
					break;
				}
				if(i>0 && mp.find(a[i]) == mp.end()){
					check = 0;
					break;
				}
				mp[a[i]] = 1;
				mp[b[i]] = 1;
			}
			if(check) cout << "YES" << endl;
			else cout << "NO" << endl;
		}
   }
	return 0;
}
