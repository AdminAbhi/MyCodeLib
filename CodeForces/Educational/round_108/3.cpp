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


inline void print(vector<VLL> &v){ for(VLL i:v) print(i);}


void sol(){
	int n; cin >> n;
	VI u(n); for(int i=0; i<n; i++) cin >> u[i];
	vector<VLL> s(n); 
	for(int i=0; i<n; i++){
		int x; cin >> x;
		s[u[i]-1].PB(x);
	} 
	for(int i=0; i<n; i++){
		sort(s[i].rbegin(), s[i].rend());
	}
	
	vector<VLL> ps(n);
	for(int i=0; i<n; i++){
		ps[i].PB(0);
		LL x = 0;
		for(int j=0; j<s[i].size(); j++){
			x += s[i][j];
			ps[i].PB(x);
		}
	}
	//print(s);
	//cout << endl;
	//print(ps);
	//cout << endl;
	
	VLL sum(n,0);
	for(int i=0; i<n; i++){
		int m = ps[i].size();
		for(int k=1; k<=m; k++){
			int j = (m-1) % k;
			sum[k-1] += ps[i][m-j-1];
		}
	}
	print(sum);
	
	
	//cout << "----" << endl;
}




int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		sol();
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
