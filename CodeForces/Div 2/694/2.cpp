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




LL sol(VLL &arr, LL n, LL x){
	LL ans = 0;
	
	queue<pair<LL, LL>> pq;
	
	for(int i=0; i<n; i++){
		pq.push({arr[i], 1});
	}
	
	while(!pq.empty()){
		auto p = pq.front(); pq.pop();
		LL curr = p.fst;
		ans += curr * p.sec;
		
		if(curr % x != 0) break;
		
		curr /= x;
		p.sec *= x;
		
		pq.push({curr, p.sec});
		
	}
	while(!pq.empty()){
		auto p = pq.front(); pq.pop();
		LL curr = p.fst;
		ans += curr * p.sec;
	}
	
	return ans;
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		LL n, x; cin >> n >> x;
		
		VLL arr(n); for(int i=0; i<n; i++) cin >> arr[i];
		
		cout << sol(arr, n, x) << endl;

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
