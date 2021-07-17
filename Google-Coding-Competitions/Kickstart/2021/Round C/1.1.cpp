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


void gen(string &s, string &g, int n, int idx, int k, LL &res){
	if((int)g.length() == (n+1)/2){
		if(s.substr(0,(n+1)/2) < g){
			return;
		}
		else{
			if(n%2==0 && s[(n+1)/2] <= g[(n+1)/2-1]) return;
			if(n%2!=0 && s.substr(0,(n+1)/2) == g) return;
			res += 1;
			//cout << g << endl;
			return;
		}
		//cout << g << endl;
	}
	
	for(int i=0; i < k; i++){
		g.push_back('a' + i);
		gen(s, g, n, idx+1, k, res);
		g.pop_back();
	}
}


void sol(){
	int n, k; cin >> n >> k;
	string s; cin >> s;
	
	if(n == 1){
		cout << s[0]-'a'<<endl;
		return;
	}
	
	string g = "";
	LL res = 0;
	
	gen(s, g, n, 0, k, res);
	
	cout << res << endl;
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
