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



bool check(int r, int g, int b, int w){
	if(w % 2 == 0 && r%2 == 0 && g%2 == 0 && b %2 ==0)return 1;
	else if(w % 2 == 1 && r%2 == 0 && g%2 == 0 && b %2 ==0)return 1;

	else if(w % 2 == 0){
		if(r%2 == 1 && g%2 == 0 && b%2 == 0) return 1;
		if(r%2 == 0 && g%2 == 1 && b%2 == 0) return 1;
		if(r%2 == 0 && g%2 == 0 && b%2 == 1) return 1;
		else return 0;
	}
	return 0;
}


int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int r, g, b, w; cin >> r >> g >> b >> w;
		int mi = min(r, min(g, b));

		if(mi == 0){
			if(check(r, g, b, w)) cout << "Yes" << endl;
			else cout << "No" << endl;
		}
		else{
			if(check(r, g, b, w)) cout << "Yes" << endl;
			else if(check(r-1, g-1, b-1, w+3)) cout << "Yes" << endl;
			else cout << "No" << endl;

		}



    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================