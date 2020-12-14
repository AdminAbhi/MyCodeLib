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


int update(VVI &mat, int i, int j, int n, int m){
	int cnt = 0;
	
	if(j > 0 && cnt < mat[i][j]){
		if(mat[i][j-1] > 0){
			cnt++;
		}
	}
	if(j < m-1){
		side++;
		if(mat[i][j+1] > 0){
			req++;
		}
	}
	if(i > 0){
		side++;
		if(mat[i-1][j] > 0){
			cnt++;
		}
	}
	if(i < n-1){
		side++;
		if(mat[i+1][j] > 0){
			req++;
		}
	}
	
	if(cnt + 2 < mat[i][j] || mat[i][j] > side) return -1;
	else return mat[i][j] - cnt - req;
}

void sol(VVI &mat, int n, int m){
	for(int i=0; i<n; i++){
		bool foo = 0;
		for(int j=0; j<m; j++){
			int r = check(mat, i, j, n, m);
			if(r == 0) continue;
			if(r < 0){
				foo = 1;
				break;
			}
			if(r == 1){
				if(j < m-1 && mat[i][j+1] == 0){
					mat[i][j+1]++;
					continue;
				}
				else if(i < n-1 && mat[i+1][j] == 0){
					mat[i+1][j]++;
					continue;
				}
				else{
					foo = 1;
					break;
				}
			}
			else if(r == 2){
				if(j < m-1 && i < n-1 && mat[i][j+1] == 0 && mat[i+1][j] == 0){
					mat[i+1][j]++;
					mat[i][j+1]++;
					continue;
				}
				else{
					foo = 1;
					break;
				}
			}
			else{
				foo = 1;
				break;
			}
		}
		if(foo){
			cout << "NO" << endl;
			return;
		}
	}
	cout << "YES" << endl;
	print(mat);
}




int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
	    int n, m; cin >> n >> m;
		VVI mat(n, VI (m));
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				cin >> mat[i][j];
			}
		}
		
		sol(mat, n, m);
	   
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
