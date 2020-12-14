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
	int T;  cin>>T;
	while(T--){
		int n; cin >> n;
		string s; cin >> s;
		//if(n%2 == 0) n--;
		int cnt = 0;
		bool ans = true;
		//string s = ss;
		
		VI hash(n,0);
		
		for(int i=0; i<n/2; i++){
			if(s[i] == s[n-i-1]) continue;
			if(i+1 == n-i-1){
				ans = false;
				break;
			}
			if(s[i+1] == s[n-i-1] && hash[i] == 0 && hash[i+1] == 0){
				swap(s[i], s[i+1]);
				hash[i] = 1;
				hash[i+1] = 1;
				cnt++;
				continue;
			} 
			if(s[i] == s[n-i-2] && hash[n-i-1] == 0 && hash[n-i-2] == 0){
				swap(s[n-i-1], s[n-i-2]);
				hash[n-i-1] = 1;
				hash[n-i-2] = 1;
				cnt++;
				continue;
			}
			ans = false;
			break;
		}
		if(ans) cout << "YES\n" << cnt << endl;
		else cout << "NO" << endl;
   }
	return 0;
}
