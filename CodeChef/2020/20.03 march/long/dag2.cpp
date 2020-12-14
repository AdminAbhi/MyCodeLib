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
	   int inf = INT_MAX/2;
	   
	   VI res(n+1), idx(n+1);
	   map<int,int> mp;
	   
	   for(int i=0; i<k; i++){
			VI temp(n+1), tp(n+1);
			for(int j=1; j<=n; j++){
				cin >> temp[j];
			} 
			if(i==0){
				for(int p=1; p<n; p++){
					res[temp[p]] = temp[p+1];
					idx[temp[p+1]] = temp[p];
					mp[temp[p]] = p;
				} 
				res[temp[n]] = n+1;
				idx[n+1] = temp[n];
				mp[temp[n]] = n;
				//print(res);
			}
			else{
				map<int, int> tmap;
				for(int p=1; p<n; p++){
					tp[temp[p]] = temp[p+1];
					tmap[temp[p]] = p;
				} 
				tp[temp[n]] = n+1;
				tmap[temp[n]] = n;
				print(tp);
				for(int p=1; p<n; p++){
					for(int q=p+1; q<=n; q++){
						if((mp[p] < mp[q] && tmap[p] > tmap[q]) || (mp[p] > mp[q] && tmap[p] < tmap[q])){
							if(res[p] == n+1){
								res[idx[p]] = n+2; 
							}
							else if(res[q] == n+1){
								res[idx[q]] = n+2;
							}
							else{
								int mi = idx[min(res[p], res[q])];
								res[mp[mi]] = res[mi];
								if(idx[mi] != 0) mp[res[mi]] = mp[mi];
								if(res[res[mi]] <=n)
									res[mi] = res[res[mi]];
								else res[mi] = n+2;
								mp[n+1] = n+1;
							}
						}
					}
				}
			}
			print(res);
			cout << "-------------\n";	
		}
		//replace(res.begin(), res.end(), INT_MAX, 0);
		for(int i=1; i<=n; i++) if(res[i] > n) res[i]=0;
		int cnt = count(res.begin()+1, res.end(), 0);
		
		cout << cnt << endl;
	   for(int i=1; i<=n; i++) cout << res[i] << " ";
	   cout << endl;
   }
	return 0;
}
