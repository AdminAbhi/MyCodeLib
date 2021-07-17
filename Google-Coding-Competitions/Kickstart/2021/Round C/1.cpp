//=============================================================================
// @abhi_admin     linkedin.com/in/adminabhi     Email: abhiavisekkr@gmail.com
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
inline void print(map<int,int> &m){for(auto i:m) print(i); cout<<endl;}

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




void sol(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	if(n == 1){
		cout << s[0]-'a' << endl;
		return;
	}
	
	LL l = (n+1)/2;
	LL res = 0;
	
	if(n%2 == 0){
		if(s[l-1] > s[l]){
			s[l-1] = s[l];
		}
	} 
	
	for(int i=0; i<l; i++){
		LL c = s[i] - 'a';
		
		res = (res + (c * power(k, l-i-1, MOD7)) % MOD7) % MOD7;
	
	}
	
	cout << res+1 << endl;
}



int main() {
	BoostIO;
	int T; cin >> T;
	int t = 1;
	while(t <= T){
		cout << "Case #" << t++ << ": ";
		sol();
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
