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
	int t=1;
	while(t <= T){
		string s; cin >> s;
		string str = "";
		
		int p = 0;
		for(unsigned int i=0; i<s.length(); i++){
			if(p <= s[i] - '0')
				for(int j=0; j < s[i] - '0' - p; j++) str.push_back('(');
			else
				for(int j=0; j < p - (s[i] - '0'); j++) str.push_back(')');
			str.push_back(s[i]);
			p = s[i]-'0';
		}
		for(int j=0; j < p; j++) str.push_back(')');
		cout << "Case #" << t << ": " << str << endl;
		t++;
   }
	return 0;
}
