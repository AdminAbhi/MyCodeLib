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
    int n, k; cin >> n >> k;
    VI arr(n); for(int i=0; i<n; i++) cin >> arr[i];
    sort(arr.begin(), arr.end());
    double den = k, num = 0;
    VPI rg(2,{-1, -1});
    int max1 = 0, max2 = 0;
    bool foo = 0;
    for(int i=0; i<n; i++){
		if(i == 0){
			if(arr[i] - 1 > max1){
				max2 = max1;
				rg[1].fst = rg[0].fst;
				rg[1].sec = rg[0].sec;
				max1 = arr[i] - 1;
				rg[0].fst = 1;
				rg[0].sec = arr[i]-1;
 			}
		}
		if(i == n-1){
			if(k - arr[i] > max1){
				max2 = max1;
				rg[1].fst = rg[0].fst;
				rg[1].sec = rg[0].sec;
				max1 = k - arr[i];
				rg[0].fst = arr[i+1];
				rg[0].sec = k;
 			}
 			else if(k - arr[i] > max2){
				max2 = k - arr[i];
				rg[1].fst = arr[i] + 1;
				rg[1].sec = k;
			}
		}
		else{
			if((arr[i+1] - arr[i])/2 > max1){
				max2 = max1;
				rg[1].fst = rg[0].fst;
				rg[1].sec = rg[0].sec;
				max1 = (arr[i+1] - arr[i])/2;
				if((arr[i+1] - arr[i] - 1) % 2 == 0) foo = 1;
				else foo = 0;
				rg[0].fst = arr[i] + 1;
				rg[0].sec = arr[i+1] - 1;
 			}
 			else if((arr[i+1] - arr[i])/2 > max2){
				max2 = (arr[i+1] - arr[i])/2;
				rg[1].fst = arr[i] + 1;
				rg[1].sec = arr[i+1] - 1;
			}
		}
	}
	
	num = max1 + max2;
	
	if(rg[0].fst != 1 && rg[0].sec != k && max1 > 1){
		if(foo == 1 && (max1 > max2)){
			num = max1 + max1;
		}
		else if(foo == 0 && (max1-1) > max2){
			num = max1 + max1-1;
		}
		
	}
	//print(rg);
	cout << num / den << endl;
    
}

int main() {
	BoostIO;
	int T; cin >> T;
	int t = 1;
	while(t <= T){
	    cout << "Case #" << t++ << ": ";
	    sol();
	}
	return 0;
}





//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
