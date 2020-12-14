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
		int n; cin >> n;
		VI arr(n);
		map<int, VI> mp;
		
 		for(int i=0; i<n; i++){
			cin >> arr[i];
			mp[arr[i]].PB(i);
		}
		int type;
		int maxx = INT_MIN;
		
		for(auto i: mp){
			int x = i.fst;

			VI v = i.sec;
			int cnt = 1;
			int l = v.size();
			int idx = v[0];
			
			for(int j=1; j<l; j++){
				if(v[j] - idx > 1){
					cnt++;
					idx = v[j];
				}
			}

			//if(v[l-1] - v[l-2] == 1) cnt++;

			if(maxx < cnt){
				maxx = cnt;
				type = x;
			}

			/*
			int cnt = 0;

			if(x == arr[n-2] && x == arr[n-1]) cnt++;
			else if(x == arr[n-2] && x != arr[n-2]) cnt = 0;
			else if(x != arr[n-2] && x == arr[n-2]) cnt++;
			
			for(int j=0; j<n-1; j++){
				if(arr[j] != x) continue;

				if(arr[j] != arr[j+1]) cnt++;
				
			}
			if(maxx < cnt){
				maxx = cnt;
				type = x;
			}
			*/
		}
		cout << type << endl;
	    
    }
	return 0;
}
