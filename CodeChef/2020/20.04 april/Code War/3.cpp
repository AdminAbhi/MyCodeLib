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

#define lim 500000

int main() {
	BoostIO;
	int n; cin >> n;
	VI arr(1000002,0);

	LL sum = 0;

	while(n--){
		int l, r; cin >> l >> r;
		arr[l + lim]++;
		arr[r + lim + 1]--;
	}

	for(int i = 1; i < 1000002; i++){
		arr[i] += arr[i-1];
	}
	for(int i=0; i < 1000001; i++){
		sum = (sum + arr[i]) % MOD7; 
	}

	cout << sum << endl;
	
	return 0;
}
