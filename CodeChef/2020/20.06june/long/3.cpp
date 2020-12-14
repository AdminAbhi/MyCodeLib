// @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI &v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> &s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();


bool for_one(int p, int q, int r, int a, int b, int c){
	
	if(a-p == b-q && b-q == c-r) return 1;
	
	else if(p == a && b == q) return 1;
	
	else if(r == c && b == q) return 1;
	
	else if(p == a && c == r) return 1;
	
	else if(p == a && (b - q == c - r)) return 1;
	
	else if(q == b && (a - p == c - r)) return 1;
	
	else if(r == c && (a - p == b - q)) return 1; 
	
	else if(p == a && q != 0 && r != 0 && (b % q == 0) && (c % r == 0) 
						&& (b/q == c/r)) return 1;
	
	else if(q == b && p != 0 && r != 0 && (a % p == 0) && (c % r == 0) 
						&& (a/p == c/r)) return 1;
	
	else if(r == c && q != 0 && p != 0 && (b % q == 0) && (a % p == 0) 
						&& (b/q == a/p)) return 1;
	
	else if(p != 0 && q != 0 && r != 0 && (a % p == 0) && (b % q == 0) 
						&& (c % r == 0) && (a/p == b/q) 
						&& (b/q == c/r)) return 1;
	
	return 0;
}

bool for_two(int p, int q, int r, int a, int b, int c){
	
	if(p == a && c-r != b-q) return 1;
	
	else if(q == b && c-r != a-p) return 1;
	
	else if(r == c && b-q != a-p) return 1;
	
	else if(b - q == c - r) return 1;
	
	else if(b - q == a - p) return 1;
	
	else if(a - p == c - r) return 1;
	
	else if(p != a && for_one(a, q, r, a, b, c)) return 1;
	
	else if(q != b && for_one(p, b, r, a, b, c)) return 1;
	
	else if(r != c && for_one(p, q, c, a, b, c)) return 1;
	
	
	
	else if(p != a && q != b && for_one(p+ abs(abs(a)- abs(p)), q+ abs(abs(a)- abs(p)), r, a, b, c)) return 1;
	else if(p != a && q != b && for_one(p- abs(abs(a)- abs(p)), q- abs(abs(a)- abs(p)), r, a, b, c)) return 1;
	else if(p != a && q != b && for_one(p+ abs(abs(a)+ abs(p)), q+ abs(abs(a)+ abs(p)), r, a, b, c)) return 1;
	else if(p != a && q != b && for_one(p- abs(abs(a)- abs(p)), q- abs(abs(a)- abs(p)), r, a, b, c)) return 1;
	

	else if(p != a && q != b && for_one(p+ abs(abs(b)- abs(q)), q+ abs(abs(b)- abs(q)), r, a, b, c)) return 1;
	else if(p != a && q != b && for_one(p+ abs(abs(b)+ abs(q)), q+ abs(abs(b)+ abs(q)), r, a, b, c)) return 1;
	else if(p != a && q != b && for_one(p- abs(abs(b)- abs(q)), q- abs(abs(b)- abs(q)), r, a, b, c)) return 1;
	else if(p != a && q != b && for_one(p- abs(abs(b)+ abs(q)), q- abs(abs(b)+ abs(q)), r, a, b, c)) return 1;
	
	
	else if(p != a && r != c && for_one(p+ abs(abs(a)- abs(p)), q, r+ abs(abs(a)- abs(p)), a, b, c)) return 1;
	else if(p != a && r != c && for_one(p+ abs(abs(a)+ abs(p)), q, r+ abs(abs(a)+ abs(p)), a, b, c)) return 1;
	else if(p != a && r != c && for_one(p- abs(abs(a)- abs(p)), q, r- abs(abs(a)- abs(p)), a, b, c)) return 1;
	else if(p != a && r != c && for_one(p- abs(abs(a)+ abs(p)), q, r- abs(abs(a)+ abs(p)), a, b, c)) return 1;
	
	
	else if(p != a && r != c && for_one(p+ abs(abs(c)- abs(r)), q, r+ abs(abs(c)- abs(r)), a, b, c)) return 1;
	else if(p != a && r != c && for_one(p+ abs(abs(c)+ abs(r)), q, r+ abs(abs(c)+ abs(r)), a, b, c)) return 1;
	else if(p != a && r != c && for_one(p- abs(abs(c)- abs(r)), q, r- abs(abs(c)- abs(r)), a, b, c)) return 1;
	else if(p != a && r != c && for_one(p- abs(abs(c)+ abs(r)), q, r- abs(abs(c)+ abs(r)), a, b, c)) return 1;
	
	
	else if(q != b && r != c && for_one(p, q+ abs(abs(b)- abs(q)), r+ abs(abs(b)- abs(q)), a, b, c)) return 1;
	else if(q != b && r != c && for_one(p, q+ abs(abs(b)+ abs(q)), r+ abs(abs(b)+ abs(q)), a, b, c)) return 1;
	else if(q != b && r != c && for_one(p, q- abs(abs(b)- abs(q)), r- abs(abs(b)- abs(q)), a, b, c)) return 1;
	else if(q != b && r != c && for_one(p, q- abs(abs(b)+ abs(q)), r- abs(abs(b)+ abs(q)), a, b, c)) return 1;
	
	
	else if(q != b && r != c && for_one(p, q+ abs(abs(c)- abs(r)), r+ abs(abs(c)- abs(r)), a, b, c)) return 1;
	else if(q != b && r != c && for_one(p, q+ abs(abs(c)+ abs(r)), r+ abs(abs(c)+ abs(r)), a, b, c)) return 1;
	else if(q != b && r != c && for_one(p, q- abs(abs(c)- abs(r)), r- abs(abs(c)- abs(r)), a, b, c)) return 1;
	else if(q != b && r != c && for_one(p, q- abs(abs(c)+ abs(r)), r- abs(abs(c)+ abs(r)), a, b, c)) return 1;
	
	
	
	
	else if(p != a && q != b && p != 0 && (a % p == 0) && for_one(a, q*(a/p), r, a, b, c)) return 1;
	
	else if(p != a && q != b && q != 0 && (b % q == 0) && for_one(p*(b/q), b, r, a, b, c)) return 1;
	
	else if(p != a && r != c && p != 0 && (a % p == 0) && for_one(a, q, r*(a/p), a, b, c)) return 1;
	
	else if(p != a && r != c && r != 0 && (c % r == 0) && for_one(p*(c/r), q, c, a, b, c)) return 1;
	
	else if(q != b && r != c && r != 0 && (c % r == 0) && for_one(p, q*(c/r), c, a, b, c)) return 1;
	
	else if(q != b && r != c && q != 0 && (b % q == 0) && for_one(p, b, r*(b/q), a, b, c)) return 1;
	
	return 0;
}


int solve(int p, int q, int r, int a, int b, int c){
	
	if(p == a && q == b && r == c) return 0;
	
	else if(for_one(p, q, r, a, b, c)) return 1;
	
	else if(for_two(p, q, r, a, b, c)) return 2;
	
	return 3;
}


int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
	    int p, q, r; cin >> p >> q >> r;
	    int a, b ,c; cin >> a >> b >> c;
	    
	    cout << solve(p, q, r, a, b, c) << endl;
    }
	return 0;
}

//    ##     ######   ##   ##  ####   #####   ##   ##     ##     ##   ##  ######   
//   ####    ##   ##  ##   ##   ##   ##   ##  ##   ##    ####    ##  ##   ##         
//  ##  ##   ##   ##  ##   ##   ##   ##       ##   ##   ##  ##   ## ##    ##         
// ##    ##  ######   #######   ##    #####   #######  ##    ##  ####     ######     
// ########  ##   ##  ##   ##   ##        ##  ##   ##  ########  ## ##    ##         
// ##    ##  ##   ##  ##   ##   ##   ##   ##  ##   ##  ##    ##  ##  ##   ##     
// ##    ##  ######   ##   ##  ####   #####   ##   ##  ##    ##  ##   ##  ######   
