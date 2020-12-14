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
		string s;cin >> s;
		int n = s.length();

		int x, y; cin >> x >> y;

		VVI hash(n+1, VI (4,0));

		int fu = n, fr = n, fd = n, fl = n;

		for(int i=n-1; i>=0; i--){

			hash[i][0] = hash[i+1][0];
			hash[i][1] = hash[i+1][1];
			hash[i][2] = hash[i+1][2];
			hash[i][3] = hash[i+1][3];

			// U, R, D, l

			if(s[i] == 'U'){
				hash[i][0]++;
				fu = i;
			}
			else if(s[i] == 'R'){
				hash[i][1]++;
				fr = i;
			}
			else if(s[i] == 'D'){
				hash[i][2]++;
				fd = i;
			}
			else {
				hash[i][3]++;
				fl = i;
			}
		}

		//print(hash);

		int q; cin >> q;
		while(q--){
			int xi, yi; cin >> xi >> yi;

			int yd = yi - y;
			int xd = xi - x;

			bool foo = 0;
			int res = -1;


			if(yd >= 0 && xd >= 0){
				if(hash[fu][0] >= yd && hash[fr][1] >= xd){
					res = yd + xd;
					foo = 1;
				}
			}
			else if(yd <= 0 && xd >= 0){
				if(hash[fd][2] >= abs(yd) && hash[fr][1] >= xd){
					res = abs(yd) + xd;
					foo = 1;
				}
			}
			else if(yd >= 0 && xd <= 0){
				if(hash[fu][0] >= yd && hash[fl][3] >= abs(xd)){
					res = yd + abs(xd);
					foo = 1;
				}
			}
			else if(yd <= 0 && xd <= 0){
				if(hash[fd][2] >= abs(yd) && hash[fl][3] >= abs(xd)){
					res = abs(yd) + abs(xd);
					foo = 1;
				}
			}
			if(foo) cout << "YES " << res << endl;
			else cout << "NO" << endl;
		}


    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
