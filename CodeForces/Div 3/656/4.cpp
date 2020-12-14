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

//=============================================================================
//--------------------------Keep-Calm-and-Code---------------------------------
//=============================================================================


int cost_s(string &s, int l, int r, char c){
	VI v(26, 0);
	for(int i=l; i<=r; i++){
		v[s[i] - 'a']++;
	}
	return r - l + 1 - v[c - 'a'];
}

int find(string &s, int l, int r, char c){
	char next_c = c == 'z'? 'a' : c+1;
	if(l == r){
		if(s[l] == c) return 0;
		else return 1;
	}
	int m = (l+r)/2;
	int c1 = cost_s(s, l, m, c);
	int c2 = cost_s(s, m+1, r, c);

	if(c1 == 0 && c2 == 0){
		int c11 = cost_s(s, l, m, next_c);
		int c22 = cost_s(s, m+1, r, next_c);
		if(c11 <= c22) return find(s, l, m, next_c);
		else return find(s, m+1, r, next_c);
	}
	else if(c1 == 0) return find(s, m+1, r, next_c);
	else if(c2 == 0) return find(s, l, m, next_c);

	if(c1 <= c2){
		return c1 + find(s, m+1, r, next_c);
	}
	else {
		return c2 + find(s, l, m, next_c);
	}
	//return c1 + c2 + half - find(s, l, m) + half - find(s, m+1, r);

}

int sol(string &s, int n, int &cost){
	return find(s, 0, n-1, 'a');
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		string s; cin >> s;

		int cost = 0;
		cout << sol(s, n, cost) << endl;


    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
