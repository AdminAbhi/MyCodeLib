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








int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	int t = 1;
	while(t <= T){
		int n, l; cin >> n >> l;
		//queue<PI> que;
		VPI arr(n);
		for(int i=0; i<n; i++){
			int a; cin >> a;
			//que.push({a, i+1});
			arr[i] = {a, i+1};
		}

		//while(!que.empty()){
		//	PI f = que.front(); que.pop();
		//	int x = min(l, f.fst);
		//	f.fst -= x;
		//	if(f.fst) que.push({f.fst, f.sec});
		//	else res.PB(f.sec);
		//}

		VI res(n, 0);

		for(int i=0; i<n; i++){
			if(arr[i].fst <= l) arr[i].fst = 1;
			else if(arr[i].fst % l == 0) arr[i].fst /= l;
			else arr[i].fst = arr[i].fst/l + 1;
		}

		sort(arr.begin(), arr.end());


		cout << "Case #" << t << ": ";
		//print(res);

		for(int i=0; i<n; i++) cout << arr[i].sec << " ";
		cout << endl;

		t++;
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

