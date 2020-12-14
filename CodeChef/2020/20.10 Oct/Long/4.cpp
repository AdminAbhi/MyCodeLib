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




int sol(VI arr, int n, int x, int k, int p){
	sort(arr.begin(), arr.end());

	int step = 0;

    if(arr[p-1] == x){
        step = 0;
    }
    else if(k == p){
        if(x > arr[p-1]){
            step = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
            step = abs(step - (k-1));
        }
        else{
            step = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
            step = abs(step - (k-1)) + 1;

        }
    }
    else if(k > p){
        if(x > arr[p-1]){
            step = -1;
        }
        else{
            step = (upper_bound(arr.begin(), arr.end(), x) - arr.begin());
            //cout << "step = " << step  << endl;
            step = abs(step - (p-1)) + 1;
        }
    }
	else {
        if(x <= arr[p-1]){
            step = -1;
        }
        else{
            step = (lower_bound(arr.begin(), arr.end(), x) - arr.begin());
            //cout << "step = " << step  << endl;

            step = abs(step - (p-1));
        }
    }
    return step;
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n, x, p, k;
	    cin >> n >> x >> p >> k;

	    vector<int> arr(n);

	    for(int i=0; i<n; i++){
	        cin >> arr[i];
	    }

	    cout << sol(arr, n, x, k, p) << endl;

    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

