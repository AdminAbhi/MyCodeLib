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
	int T;  cin >> T;

	srand(time(0));
	
	while(T--){
	   int n, m, k; cin >> n >> m >> k;
	   
	   VVI arr(n, VI(k));
	   VI most(n);
	   for(int i=0; i<n; i++){
			VI hash(10,0);
			for(int j=0; j<k; j++){
				cin >> arr[i][j];
				hash[arr[i][j]]++;
			}
			int max_idx = max_element(hash.begin(), hash.end()) - hash.begin();
			//int max_cnt = hash[max_idx];
			//int idx = lower_bound(hash.begin(), hash.end(), (max_cnt/2)) - hash.begin();
			most[i] = max_idx;
		}
	   
	   VI res;
	   res.PB(0);
	   
	   for(int i=0; i<k; i++){
			int r = 0;
			for(int k=0; k<n; k++){
				if(arr[k][i] == most[k]) r++;
			}
			if(r > n/3) res.PB(i);
		}
		
		
			//for(int i=0; i<n; i++){
			//	cout << (rand() % m) + 1 << " ";
			//}
			//cout << endl;

		
	   //int idx = max_element(res.begin(), res.end()) - res.begin();

		int idx = rand() % res.size();
		idx = res[idx];
		
		for(int i=0; i<n; i++){
			cout << arr[i][idx] << " ";
		}
		cout << endl;
   }
	return 0;
}
