//=============================================================================
// @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
//=============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int, int> PI;
typedef vector<PI> VPI;

#define endl "\n"
#define fst first
#define sec second
#define PB push_back
#define MP make_pair
#define MOD7 1000000007
#define uset unordered_set
#define umap unordered_map
#define BoostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl;}
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl;}
inline void print(VVI &v){ for(VI i:v) print(i);}
inline void print(PI p){ cout<<"("<<p.fst<<":"<<p.sec<<"), ";}
inline void print(VPI &P){for(PI i:P) print(i); cout<<endl;}
inline void print(set<int> &s){for(int i:s)cout<<i<<" "; cout<<endl;}
inline void print(map<int,int> m){for(auto i:m) print(i); cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

LL power(LL a, LL b, LL MOD){
    LL res = 1;
    while(b){
        if(b%2) res = (res*a) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }return res;
}
LL iMOD(LL a, LL p){
    return power(a, p-2, p);
}
//=============================================================================
//--------------------------Keep-Calm-and-Code---------------------------------
//=============================================================================








int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int pp, ff; 	cin >> pp >> ff;
		VPI tool(2);
		cin >> tool[0].sec >> tool[1].sec;
		cin >> tool[0].fst >> tool[1].fst;

		sort(tool.begin(), tool.end());

		int gans = 0;

		int s, w;

		if(pp >= ff){

			for(int i=1; i<= min(pp/tool[0].fst, tool[0].sec); i++){
				int ans = 0;
				int p = pp, f = ff;

				int t0f = tool[0].fst;
				int t0s = tool[0].sec;
				int t1s = tool[1].fst;
				int t1s = tool[1].sec;

				//s = min(p/tool[0].fst, tool[0].sec);
				t0s -= i;

				p -= i * t0f;

				w = min(p / t1f, t1s);

				t1s -= w;

				p -= w * t1f;

				ans += s + w;

				s = min(f/t0f, t0s);
				t0s -= s;

				f -= s * t0f;

				w = min(f/t1f, t1s);
				t1s -= w;

				f -= w * t1f;

				ans += s + w;

			}
		}
		else{

			s = min(f/tool[0].fst, tool[0].sec);
			tool[0].sec -= s;

			f -= s * tool[0].fst;

			w = min(f/tool[1].fst, tool[1].sec);
			tool[1].sec -= w;

			f -= w * tool[1].fst;

			ans += s + w;

			cout << s << " " << w << endl;

			s = min(p/tool[0].fst, tool[0].sec);
			tool[0].sec -= s;

			p -= s * tool[0].fst;

			w = min(p/tool[1].fst, tool[1].sec);
			tool[1].sec -= w;

			p -= w * tool[1].fst;

			ans += s + w;

			cout << s << " " << w << endl;

		}

		cout << ans << endl;

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

