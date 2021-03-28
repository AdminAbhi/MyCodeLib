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
	int n, q; cin >> n >> q;
	string s; cin >> s;
	set<int> st;
	int x = 0; st.insert(x);
	
	VPI arr(n+2, {1,1});
	arr[0].fst = 0;
	arr[0].sec = 0;
	
	for(int i=0; i<n; i++){
		if(s[i]=='-') x--;
		else x++;
		
		arr[i+1].fst = min(arr[i].fst, x);
		arr[i+1].sec = max(arr[i].sec, x);
		
	}
	
	arr[n+1].fst = arr[n].fst;
	arr[n+1].sec = arr[n].sec;
	
	print(arr);
	
	while(q--){
		int l, r; cin >> l >> r;
		
		int mini = arr[n+1].fst + (arr[l-1].fst - arr[r].fst);
		int maxi = arr[n+1].sec - (arr[r].sec - arr[l-1].sec);
		
		cout << maxi - mini + 1 << endl;
	}
	

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
