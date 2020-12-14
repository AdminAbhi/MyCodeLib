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
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();





int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		int n, k; cin >> n >> k;
		
		VI arr(n), req(n); 
		
		for(int i=0; i<n; i++){
			cin >> arr[i];
			req[i] = (arr[i] % k) == 0? 0 : k - (arr[i] % k);
		} 
		
		sort(req.begin(), req.end());
		
		LL step = 0;
		LL x = 0;
		
		for(int i=0; i<n; i++){
			if(req[i] == 0){
				continue;
			} 
			
			//if(req[i] == req[i-1]) req[i] += k;
			
			int r = x % k;
			
			if(r < req[i]){
				if(x % k == 0){
					step += req[i] - r + 1;
					x += req[i] - r + 1;
				}
				else{
					step += req[i] - r + 1;
					x += req[i] - r;
				}
				
			}
			else if(r == req[i]){
				step++;
				x++;
			}
			else{
				if(x%k == 0){
					step += k - r + req[i] + 1;
					x += k - r + req[i] + 1;
				}
				else{
					step += k - r + req[i] + 1;
					x += k - r + req[i];
				}
			}
			//req[i] += x;
		}
		
		

		
		//print(req);
		
		cout << step << endl;
		
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

