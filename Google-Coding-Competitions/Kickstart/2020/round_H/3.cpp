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

		cout << "Case #" << t++ << ": ";

        int n; cin >> n;

        vector<pair<long long, long long>> xy(n); for(int i=0; i<n; i++) cin >> xy[i].fst >> xy[i].sec;

        sort(xy.begin(), xy.end());

        LL meanX = 0, meanY = 0;

        for(int i=0; i<n; i++){
            meanX += xy[i].fst;
            meanY += xy[i].sec;
        }
        meanX = round(double(meanX) / n);
        meanY = round(double(meanY) / n);

        vector<pair<long long, long long>> pos(n);
        int counter = 0;
        for(int i=n/2; i>=0; i--){
            pos[i].fst = meanX - counter++;
            pos[i].sec = meanY;
        }
        counter = 1;
        for(int i=n/2+1; i<n; i++){
            pos[i].fst = meanX + counter++;
            pos[i].sec = meanY;
        }

        LL steps = 0;

        for(int i=0; i<n; i++){
            steps += abs(pos[i].fst - xy[i].fst);
            steps += abs(pos[i].sec - xy[i].sec);
        }

        cout << steps << endl;
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

