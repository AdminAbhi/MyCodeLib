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
#define PB push_back
#define MP make_pair
#define fst first
#define sec second
#define MOD7 1000000007
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
	   int n, k; cin >> n >> k;
	   VVI krr(k);
	   
	   for(int i=0; i<k; i++){
			krr[i].resize(n,0);
			for(int j=0; j<n; j++) cin >> krr[i][j];
		}
		//print(krr);
	   
	   VVI dag(n+1);
	   for(int i=0; i<n+1; i++) dag[i].resize(n+1,0);
	   
	   for(int i=0; i<n-1; i++) dag[krr[0][i]][krr[0][i+1]] = krr[0][i+1];
	   
		//print(dag);
		
		for(int i=0; i<k; i++){
			vector<bool> boo(n+1,0);
			for(int j=0; j<n-1; j++){
				if(boo[krr[i][j]] == 1){
					for(int kk=0; kk<n+1; kk++){
						dag[kk][krr[i][j]] = 0;
						dag[krr[i][j]][kk] = 0;
					}
				}
				else if(dag[ krr[i][j+1] ][ krr[i][j] ] != 0){
					dag[ krr[i][j+1] ][ krr[i][j] ] = 0;
					if(j+2 < n) dag[ krr[i][j+1] ][ krr[i][j+2] ] = krr[i][j+2];
				}
				boo[krr[i][j]] = 1;
			}
		}
		VI res(n);
		int count = 0;
		
		for(int i=0; i<n; i++){
			res[i] = dag[i+1][max_element(dag[i+1].begin(), dag[i+1].end()) - dag[i+1].begin()];
			if(res[i] == 0) count++;
		}
		cout << count << endl;
		print(res);
		
    }
	return 0;
}
