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




void sol(string &s, int n){
	bool c0 = 0, c1 = 0;
	for(char i: s){
		if(i == '0') c0 = 1;
		if(i == '1') c1 = 1;
	}
	if(c0 == 0 || c1 == 0){
		cout << n << endl;
		for(int i=1; i<=n; i++) cout << i << " ";
		cout << endl;
		return;
	}
	int nog = 0;
	VI hash(n,0);
	for(int i=0; i<n; i++){
		if(hash[i] != 0) continue;
		nog++;
		bool foo = 1;
		string ss = ".";
		bool check = 1;
		for(int j=i; j<n; j++){
			if(hash[j] != 0){
				if(check) i++;
				continue;
			}
			check = 0;
			foo = 0;
			if(ss.back() != s[j]){
				hash[j] = nog;
				ss.PB(s[j]);
			}
		}
		if(foo) break;
	}

	cout << nog << endl;
	print(hash);
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		string s; cin >> s;

		sol(s, n);

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
