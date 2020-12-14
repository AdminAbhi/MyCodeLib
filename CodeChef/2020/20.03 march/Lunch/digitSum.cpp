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

int sum(int a, int b, int c, int d){
		return a*10 + b + c*10 + d;
}

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
	   int a,b; cin >> a >> b;
	   if(a<10 && b<10){
			cout << a+b << endl;
			continue;
		}
		if(a>=10 && b<10){
			if(a/10 < b){
				cout << (b*10)+(a%10) + a/10 << endl;
			}
			else cout << a + b << endl;
			continue;
		}
		if(b>=10 && a<10){
			if(b/10 < a){
				cout << (a*10)+(b%10) + b/10 << endl;
			}
			else cout << a + b << endl;
			continue;
		}
		
		VI aa(2), bb(2);
		aa[0] = a/10;
		aa[1] = a%10;
		bb[0] = b/10;
		bb[1] = b%10;
		
		int max = a+b, x;
		
		x = sum(bb[0], aa[1], aa[0], bb[1]); if(x > max) max = x;
		x = sum(bb[1], aa[1], bb[0], aa[0]); if(x > max) max = x;
		x = sum(aa[0], bb[0], aa[1], bb[1]); if(x > max) max = x;
		x = sum(aa[0], bb[1], bb[0], aa[1]); if(x > max) max = x;
		
		cout << max << endl;
		
   }
	return 0;
}
