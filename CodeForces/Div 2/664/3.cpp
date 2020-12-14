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

int cost(int a, int b){
	int i = 0;
	int loop = 15;
	int cost = 0;
	while(loop--){
		if((a & ((int)1 << i)) != (b & (int)1 << i))) cost += pow(2, i);
		i++;
	}
	return cost;
}

int sol(VI &a, VI &b, int n, int m){
	int res = 0;
	VVI mat(n, VI (m));
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			mat[i][j] = cost(a[i], b[i]);
		}
	}
	int gm = INT_MAX;
	for(int k=0; k<m; k++){
		int mi = cost(a[0], b[j]);
		for(int i=0; i<n; i++){
			int jj;
			int d = INT_MAX;
			for(int j=0; j<m; j++){
				if(abs(mat[i])
			}
		}
	}


	return res;
}




int main() {
	BoostIO;
	int T = 1;
	//cin >> T;
	while(T--){
		int n, m; cin >> n >> m;

		VI a(n), b(m);
		for(int i=0; i<n; i++) cin >> a[i];
		for(int i=0; i<m; i++) cin >> b[i];

		cout << sol(a, b, n, m) << endl;


    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
