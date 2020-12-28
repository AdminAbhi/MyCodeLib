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



bool sol(VI &height, int n, int k){
	vector<pair<PI, PI>> back(n); 
	back[n-1].fst.fst = n-1;
	back[n-1].fst.sec = height[n-1];
	back[n-1].sec.fst = n-1;
	back[n-1].sec.sec = height[n-1];
		
	int maxh = height[n-1];
	int minh = height[n-1];
		
	for(int i=n-2; i>=0; i--){
		if(height[i] >= maxh){
			maxh = height[i];
			back[i].fst.fst = i;
			back[i].fst.sec = maxh;
		}
		else{
			back[i].fst.fst = back[i+1].fst.fst;
			back[i].fst.sec = back[i+1].fst.sec;
		}
		if(height[i] <= minh){
			minh = height[i];
			back[i].sec.fst = i;
			back[i].sec.sec = minh;
		}
		else{
			back[i].sec.fst = back[i+1].sec.fst;
			back[i].sec.sec = back[i+1].sec.sec;
		}
	} 
	for(int i=0; i<n; i++){
		if(abs(back[i].fst.sec - back[i].sec.sec) > 
			(k-1)*(1 + abs(i - back[i].fst.fst) + abs(i - back[i].fst.fst))) 
				return 0;
	}
	return 1;
}




int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n, k; cin >> n >> k;
		VI height(n); for(int i=0; i<n; i++) cin >> height[i];
		
		if(sol(height, n, k)) cout << "YES" << endl;
		else cout << "NO" << endl;
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
