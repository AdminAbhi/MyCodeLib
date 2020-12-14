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
	while(T--){
        LL n, q; cin >> n >> q;
        VLL arr(n);
        for(int i=0; i<n; i++){
            cin >> arr[i];
        }
        LL len = 1;
        for(int i=1; i<n; i++){
            if(arr[i] != arr[i-1]){
                len++;
            }
        }
        while(q--){
            LL idx, val; cin >> idx >> val;
            int prev = arr[idx-1];
            arr[idx-1] = val;

            if(idx-1 > 0 && arr[idx-1] != prev && arr[idx-1] == arr[idx-2]){
                len--;
            }
            else if(idx-1 > 0 && arr[idx-1] != prev && prev == arr[idx-2]){
                len++;
            }
            if(idx-1 < n-1 && arr[idx-1] != prev && arr[idx-1] == arr[idx]){
                len--;
            }
            else if(idx-1 < n-1 && arr[idx-1] != prev && prev == arr[idx]){
                len++;
            }

            cout << len << endl;
        }

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
