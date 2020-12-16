//==========================================================================
// @abhi_admin      FB-Id: abhiavisekkr     Email-Id: abhiavisekkr@gmail.com
//==========================================================================
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
#define dbg(x, y) cout << x << " = " << y << endl
#define BoostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl;}
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl;}
inline void print(VVI &v){ for(VI i:v) print(i);}
inline void print(PI p){ cout<<"("<<p.fst<<":"<<p.sec<<"), ";}
inline void print(VPI &P){for(PI i:P) print(i); cout<<endl;}
inline void print(set<int> &s){for(int i:s)cout<<i<<" "; cout<<endl;}
inline void print(map<int,int> m){for(auto i:m) print(i); cout<<endl;}

//ifstream fin; ofstream fout; fin.open("input.txt");
//fout.open("output.txt");fin >> x; fout << x;fin.close(); fout.close();

//==========================================================================
//--------------------------Keep-Calm-and-Code------------------------------
//==========================================================================



void getst(int idx, int l, int r, VI &st, VI &arr){
	if(l==r){
		st[idx] = arr[l];
		return;
	} 
	int mid = (l + r)/2;
	
	getst(2*idx+1, l, mid, st, arr);
	getst(2*idx+2, mid+1, r, st, arr);
	
	st[idx] = st[2*idx+1] + st[2*idx+2];
}

int querry(int idx, int s, int e, int qs, int qe, VI &st){
    if(s > qe || e < qs) return INT_MIN;
    
    if(s >= qs && e <= qe) return st[idx];

    int mid = (s + e)/2;

    return max(querry(2*idx +1, s, mid, qs, qe, st), 
				querry(2*idx +2, mid+1, e, qs, qe, st));
}



int main() {
	BoostIO;
	
	int n; cin >> n;
	VI arr(n); for(int i=0; i<n; i++) cin >> arr[i];
	
	VI st(4*n, INT_MIN);
	getst(0, 0, n-1, st, arr);
	//print(st);
	
	int q; cin >> q;
	while(q--){
		int l, r; cin >> l >> r;
		cout << querry(0, 0, n-1, l-1, r-1, st) << endl;
	}
	
	return 0;
}


//==========================================================================
//--------------------------------------------------------------------------
//    ##    ######  ##   ##  ####    #####  ##   ##    ##    ##   ## ######   
//   ####   ##   ## ##   ##   ##    ##   ## ##   ##   ####   ##  ##  ##         
//  ##  ##  ##   ## ##   ##   ##    ##      ##   ##  ##  ##  ## ##   ##         
// ##    ## ######  #######   ##     #####  ####### ##    ## ####    ######     
// ######## ##   ## ##   ##   ##         ## ##   ## ######## ## ##   ##         
// ##    ## ##   ## ##   ##   ##    ##   ## ##   ## ##    ## ##  ##  ##     
// ##    ## ######  ##   ##  ####    #####  ##   ## ##    ## ##   ## ######   
//--------------------------------------------------------------------------
//==========================================================================
