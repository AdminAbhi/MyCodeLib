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
inline void print(set<int> s){for(auto i:s) cout << i <<" "; cout << endl;}
inline void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<" ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();
 
int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
		int n; cin >> n;
		VI arr(n);
		for(int i=0; i<n; i++) cin >> arr[i];

		int p; cin >> p;
		
		sort(arr.begin(), arr.end(), greater<int> ());

		VVI mat(n + 1, VI (p+1, 0));

		int res = INT_MAX;

		bool flag = 1;

		for(int i=1; i<n; i++){
			bool foo = 0;
			for(int j=1; j<=p; j++){
				if(j < arr[i-1]) continue;

				if(j == p && j % arr[i-1] == 0){
					foo = 1;
					flag = 0;
					cout << j / arr[i-1] << endl;
					break;
				}
				
				if(j % arr[i-1] == 0) mat[i][j] = j / arr[i-1];

				else mat[i][j] = min(mat[i-1][j],  mat[i][j - arr[i]]);

				if(j == p && mat[i][j] > 0){
					foo = 1;
					flag = 0;
					cout << mat[i][j] << endl;
					break;
				}
				
			}
			if(foo) break;
		}
	       
    }
	return 0;
}
