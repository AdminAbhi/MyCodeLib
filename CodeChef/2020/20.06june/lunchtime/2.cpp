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


bool cmp(pair<double, double> &a, pair<double, double> &b){
	return (a.sec/a.fst) > (b.sec/b.fst);
}


int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		int n; cin >> n;
		vector<pair<double, double>> ga(n), gb(n);
		for(int i=0; i<n; i++){
			double g, a, b;
			cin >> g >> a >> b;
			
			ga[i].fst = a;
			ga[i].sec = g;
			
			gb[i].fst = b;
			gb[i].sec = g;
		}
		sort(ga.begin(), ga.end(), cmp);
		sort(gb.begin(), gb.end(), cmp);
		
		double res1 = 0, res2 = 0;
		
		int idx1 = ga[0], idx2 = 0;
		int d1 = ga[0].fst, d2 = gb[0].fst;
		 
		while(1){
			int mind = min(d1, d2);
			
			if(idx1 == idx2)
			while(mind > 0){
				int nod = mind;
				for(int i = idx1; i<n && nod > 0; i++){
					if(ga[idx1].sec)
				}
			}
		}
		
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

