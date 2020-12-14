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
		int n, m;
		cin >> n;
		VI a(n);
		for(int i=0; i<n; i++) cin >> a[i];

		cin >> m;
		unordered_map<int , int> mp;
		VI b(m);

		for(int i=0; i<m; i++){
			cin >> b[i];
			mp[b[i]]++;
		} 

	    int cnt = 0;
	    bool flag = 0;
	    for(int i=0; i<n; i++){

			if(mp.find(a[i]) == mp.end()){
				flag = 0;
				continue;
			}
			
			if(flag == 0 && mp.find(a[i]) != mp.end()){
				flag = 1;
				cnt++;
			}
			
		}
		cout << cnt << endl;
    }
	return 0;
}
