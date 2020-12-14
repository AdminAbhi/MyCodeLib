//@Abhi     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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
	int T;  cin >> T;
	while(T--){
		int n; cin >> n;
		if(n%4 != 0){
			cout << "NO" << endl;
			continue;
		}
		VI arr(n);
		for(int i=0; i<n/2; i++){
			arr[i] = (i+1)*2;
		}
		for(int i=0; i<n/4; i++){
			arr[n/2 + i] = arr[i] -1;
		}
		for(int i=n/4; n/2 + i < n; i++){
			arr[n/2 + i] = arr[i] +1;
		}
		cout << "YES" << endl;
		print(arr);
    }
	return 0;
}
