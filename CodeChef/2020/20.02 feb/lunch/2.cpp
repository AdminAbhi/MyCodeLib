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

bool cmp(VI a, VI b){
	return a.size() < b.size();
}

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
	   int n, k; cin >> n >> k;
	   VI cake(n);
	   VVI hash(k);
	   for(int i=0; i<n; i++){
			cin >> cake[i];
			hash[cake[i]-1].PB(i+1);
		} 
		sort(hash.begin(), hash.end(), cmp);
		//print(hash);
		
		if(hash[0].size() == 0) cout << n << endl;
		else {
			//unsigned int j = hash[0].size();
			int maxx = INT_MIN;
			for(int p =0; p < k; p++){
				
				int diff = hash[p][0]-1;
				for(unsigned int i=0; i<hash[p].size()-1; i++){
					int x = hash[p][i+1] - hash[p][i] -1;
					if(x > diff) diff = x;
				}
				int x = n - hash[p][hash[p].size()-1];
				if(x > diff) diff = x;
				
				if(diff > maxx) maxx = diff;
			}
			cout << maxx << endl;
		}
    }
	return 0;
}
