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


int sol(VI &arr, int n){
	int cnt = 0;
	
	if(n==1) return 1;
	
	VI pre(n,0), pos(n,0);
	pre[0] = arr[0];
	
	for(int i=1; i<n; i++){
		pre[i] = max(pre[i-1], arr[i]);
	}
	
	pos[n-1] = arr[n-1];
	
	for(int i=n-2; i>=0; i--){
		pos[i] = max(pos[i+1], arr[i]);
	}
	
	for(int i=0; i<n; i++){
		if(i==0 && arr[i] > arr[i+1]){
			cnt++;
		}
		else if(i > 0 && i < n-1 && arr[i] > pre[i-1] && arr[i] > arr[i+1]){
			cnt++;
		}
		else if(i == n-1 && arr[i] > pre[i-1]){
			cnt++;
		}
	}
	return cnt;
}


int main() {
	BoostIO;
	int T;  cin >> T;
	for(int t=1; t<=T; t++){
	    int n; cin >> n;
	    VI arr(n); for(int i=0; i<n; i++) cin >> arr[i];
	    
	    
	    cout << "Case #" << t << ": " << sol(arr, n) << endl;
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
