// @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

//#define endl "\n"
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

bool cmp(VI a, VI b){
	return a[1] < b[1]; 
}

int main() {
	//BoostIO;
	int T;  cin>>T;
	int t=1;
	while(t <= T){
		int a, b, n;
		cin >> a >> b >> n;
		int s = a, e = b, m;
		while(s < e){
			m = (s + e)/2;
			cout << m << endl;
			fflush(stdout);
			string str;
			cin >> str;
			if(str == "TOO_BIG"){
				e = m;
			}
			else if(str == "TOO_SMALL"){
				s = m+1;
			}
			else if(str == "CORRECT"){
				break;
			}
			else return 0;
		}
		
		
		//cout << "Case #" << t << ": " << res << endl;
		t++;
   }
	return 0;
}
