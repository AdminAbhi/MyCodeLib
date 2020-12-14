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
	//VLL bit(62,1); for(int i=1; i<62; i++) bit[i] = bit[i-1]*2; 
	//print(bit);
	while(T--){
		int n,q; cin >> n >> q;
	   VI arr(n), prr(q), brr(n);
	   
	   for(int i=0; i<n; i++) cin >> arr[i];
	   for(int i=0; i<q; i++) cin >> prr[i];
	   
	   int odd=0, even=0;
		for(int i=0; i<n; i++){
			int b = arr[i];
			int no1=0;
			while(b){
				no1 += b & 1;
				b >>= 1; 
			}
			if(no1 % 2 == 0) even++;
			else odd++;
		}
		
	   for(int i=0; i<q; i++){
			int e = even, o = odd;
			int b = prr[i];
			int no1=0;
			while(b){
				no1 += b & 1;
				b >>= 1; 
			}
			if(no1 % 2 != 0){
				e = odd;
				o = even;
			}
			cout << e << " " << o << endl;
		}
	}
	return 0;
}
