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
	   int n, k; cin >> n >> k;
	   vector<char> coins(n);
	   for(int i=0; i<n; i++) cin >> coins[i]; 
	   
	   for(int i=0; i<k; i++){
			if(coins[n-1] == 'H'){
				for(int j=0; j<n; j++){
					if(coins[j] == 'H') coins[j] = 'T';
					else coins[j] = 'H';
				}
			}
			n--;
		}
		int count=0; 
		for(int i=0; i<n; i++) if(coins[i] == 'H') count++;
 	   cout << count << endl;
    }
	return 0;
}
