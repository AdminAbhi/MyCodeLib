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

#define MX 1000000

int main() {
	//BoostIO;
	int T;  cin>>T;
	
	while(T--){
		int n; cin >> n;
		if(n==1){
			cout << 1 << endl;
			cout << 1 << " " << 1 << endl;
			continue;
		}
		int idx = 1;
		printf("%d\n", n/2);
		
		if(n % 2 == 0){
			printf("2 %d %d\n", idx, idx+1);
			idx += 2;
		}
		else{
			printf("3 %d %d %d\n", idx, idx+1, idx+2);
			idx += 3;
		}
		
		for(int i=idx; i<=n; i+=2){
			printf("2 %d %d\n", i, i+1);
		}
   }
	return 0;
}