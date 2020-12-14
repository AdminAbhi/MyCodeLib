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



bool check(unordered_map<int, int> &mp){
	int side = -1;
	int mini = INT_MAX;
	vector<int> two;
	vector<int> four;

	for(auto i:mp){
		if(i.sec >= 8) return 1;
		if(i.sec >= 4 && i.sec < mini){
			side = i.fst;
			mini = i.sec;
		}
		if(i.sec >= 4) four.PB(i.sec);
		else if(i.sec >= 2) two.PB(i.sec);
	}
	if(four.size() >= 2) return 1;
	if(four.size() == 1 && two.size() >= 2) return 1;

	if(four.size() == 1 && four[0] >= 6 && two.size() == 1) return 1;

	return 0;
}




int main() {
	BoostIO;
	int T = 1;
	//cin >> T;
	while(T--){
		int n; cin >> n;
		//VI arr(n);
		unordered_map<int, int> mp;

		for(int i=0; i<n; i++){
			//cin >> arr[i];
			int x; cin >> x;
			mp[x]++;
		}

		int q; cin >> q;
		while(q--){
			char c; cin >> c;
			int x; cin >> x;

			if(c == '+'){
				mp[x]++;
				if(check(mp)) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
			else{
				mp[x]--;
				if(check(mp)) cout << "YES" << endl;
				else cout << "NO" << endl;
			}
		}

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
