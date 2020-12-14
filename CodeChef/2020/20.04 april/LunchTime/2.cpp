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
		VI arr(n);
		for(int i=0; i<n; i++) cin >> arr[i];

		if(k == 1){
			cout << "yes" << endl;
			continue;
		}

		bool flag = 1;
		//print(arr);
	    for(int i=0; i<n-1; i++){
			if(arr[i] > arr[i+1]){
				//cout << "no" << endl;
				flag = 0;
				break;
			}
		}
		if(flag){
			cout << "yes" << endl;
			continue;
		} 
		
		for(int i=0; i<n-k; i++){
			int j = i;
			VI v;
			while(j < n){
				v.PB(arr[j]);
				j += k;
			}
			sort(v.begin(), v.end());
			j = i;
			int idx = 0;
			while(j < n){
				arr[j] = v[idx++];
				j += k;
			}
		}
		flag = 1;
		//print(arr);
	    for(int i=0; i<n-1; i++){
			if(arr[i] > arr[i+1]){
				cout << "no" << endl;
				flag = 0;
				break;
			}
		}
		if(flag) cout << "yes" << endl;
    }
	return 0;
}
