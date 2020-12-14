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

LL powr(LL b, LL p){
	LL res = 1;
	while(p--) res = (res*b)%MOD7;
	return res;
}

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
		LL n, v; cin >> n >> v;
		LL tot = n*n;
		LL dec = 1;
		tot -= dec;
		LL p = 1;

		VI arr;
		arr.PB(p);

		
		
		while(tot > 0){	
			p += p*dec;
			
			dec += 2;
			arr.PB(p*dec);
			tot -= dec;
		}
		p *= (n+n-1);
		//print(arr);

		LL res = 0;
		for(int i=0; i<arr.size(); i++){
			res = (res + powr(v, arr[i])) % MOD7;
		}
		//cout << p << "--p\n";
		//LL res = 1;
		//while(p--){
		//	res *= v;
		//	res %= MOD7;
		//}

		cout << res << endl;
    }
	return 0;
}
