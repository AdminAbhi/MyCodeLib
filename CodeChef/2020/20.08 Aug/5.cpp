//==============================================================================
// @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
//==============================================================================
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

//==============================================================================
//--------------------------Keep-Calm-and-Code----------------------------------
//==============================================================================

int get_mini(VVI &dp, int i, int n, int k, int cost){
	if(i==n-1) return 0;
	bool same = dp[i][n-1] == dp[i+1][n-1];

	if(same){
		return get_mini(dp, i+1, n, k, cost);
	}
	else{
		return 0;
	}

	int diff = k + dp[i][i+1];
	return 0;

}

VVI get_DP_table(VI &fam, int n, int k){
	VVI dp(n, VI (n));
	for(int i=0; i<n; i++){
		unordered_map<int, int> mp;
		int cost = k;
		for(int j=i; j<n; j++){
			if(i != j && mp.find(fam[j]) != mp.end()){
				if(mp[fam[j]] == 1) cost += 2;
				else cost++;
			}
			dp[i][j] = cost;
			mp[fam[j]]++;
		}
	}
	return dp;
}


int sol(VI &fam, int n, int k){

	VVI dp = get_DP_table(fam, n, k);
	//print(dp);

	// 1 table
	int cost = dp[0][n-1];

	// 2 table
	for(int i=0; i<n-1; i++) cost = min(cost, dp[0][i] + dp[i+1][n-1]);

	// 3 table
	for(int i=0; i<n-2; i++){
		for(int j=i+1; j<n-1; j++){
			cost = min(cost, dp[0][i] + dp[i+1][j] + dp[j+1][n-1]);
		}
	}


	return cost;
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n, k; cin >> n >> k;
		VI fam(n); for(int i=0; i<n; i++) cin >> fam[i];

		cout << sol(fam, n, k) << endl;

	}
	return 0;
}


//===============================================================================
//-------------------------------------------------------------------------------
//    ##     ######   ##   ##  ####   #####   ##   ##     ##     ##   ##  ######
//   ####    ##   ##  ##   ##   ##   ##   ##  ##   ##    ####    ##  ##   ##
//  ##  ##   ##   ##  ##   ##   ##   ##       ##   ##   ##  ##   ## ##    ##
// ##    ##  ######   #######   ##    #####   #######  ##    ##  ####     ######
// ########  ##   ##  ##   ##   ##        ##  ##   ##  ########  ## ##    ##
// ##    ##  ##   ##  ##   ##   ##   ##   ##  ##   ##  ##    ##  ##  ##   ##
// ##    ##  ######   ##   ##  ####   #####   ##   ##  ##    ##  ##   ##  ######
//-------------------------------------------------------------------------------
//===============================================================================
