//@Abhi     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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
 
void dfs(VI &arr, int &maxl, VI &vis, int x, bool sign){
	if(x < 0 || x >= arr.size()) return;

	bool s;
	if(arr[x] >= 0) s = 1;
	else s = 0;
		
	if(vis[x] == 1 || s == sign) return;
	
	maxl++;
	vis[x] = 1;

	dfs(arr, maxl, vis, x+1, s);
	dfs(arr, maxl, vis, x-1, s);
}

int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		int n; cin >> n;
		VI arr(n);
		for(int i=0; i<n; i++) cin >> arr[i];
		VI vis(n,0);

		int k = 0;
		int idx;
			
		for(int i=0; i<n; i++){
			if(vis[i] == 0){
				bool sign;
				if(arr[i] >= 0) sign = 1;
				else sign = 0;

				int maxl = 0;
			
				dfs(arr, maxl, vis,i, 1-sign);

				if(k < maxl){
					k = maxl;
					idx = i;
				} 
			}
		}
		//cout << k << endl;
		LL maxSum = LONG_MIN;

		for(int i=0; i+k <= n; i++){
			LL sum = 0;
			for(int j=i; j<i+k; j++){
				sum += arr[j];
			}
			maxSum = max(maxSum, sum);
		}
		cout << maxSum << endl;
    }
	return 0;
}
