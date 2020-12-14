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

#define MX 1000000

int main() {
	//BoostIO;
	int T;  cin >> T;
	VI hash(MX+1,1);
	
	for(int i=2; i<=MX; i++){
		if(hash[i] != 1) continue;	
		for(int j = i; j<=MX; j += i){
			if(hash[j] != 1) continue;
			hash[j] = i;
		}
	}
	//print(hash);
	
	while(T--){
		int n; cin >> n;
		if(n==1){
			cout << 1 << endl;
			cout << 1 << " " << 1 << endl;
			continue;
		}
		
		map<int, VI> mp;
		
		for(int i=1; i<=n; i++){
			mp[hash[i]].PB(i);
		}
		//cout << mp.size() << endl;
		
		//VVI res(n/2);
		vector<pair<map<int,int>, VI>> res(n/2);
		
		//for(auto i: mp){
		//	VI v = i.sec;
		//	//print(v);
		//}
		
		for(auto i: mp){
			VI v = i.sec;
			//print(v);
			
			unsigned int idx = 0;
		
			for(int j : v){
				if(idx == 0) {
					res[0].sec.PB(j);
					idx++;
					continue;
				}
				
					VI pf;
					int x = j;
					int tp;
					//bool c = true;
					while(x != 1){
						tp = hash[x];
						if(res[idx].fst.find(tp) != res[idx].fst.end()){
							idx++;
							x = j;
							VI xxx;
							pf = xxx;
							continue;
						}
						pf.PB(tp);
						x = x / tp;
					
						while(x % tp == 0){
							x = x / tp;
						}
					}
					//if(c){
						for(int z : pf){
							res[idx].fst[z] = 1;
						}
						res[idx].sec.PB(j);
						idx++;
					//}
			}
		}
		
		//print(res);
		
		
		printf("%d\n", n/2);
		for(int i=0; i< n/2; i++){
			printf("%ld", res[i].sec.size());
			for(auto j: res[i].sec){
				printf(" %d", j);
			}
			printf("\n");
		}
		
   }
   
	return 0;
}
