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

int nop(VPI &poi, int x1, int x2){
	int cnt = 0;
	
	for(unsigned int i = 0; i < poi.size(); i++){
		if(poi[i].fst < x1) continue;
		if(poi[i].fst > x2) break;
		
		if(x1 <= poi[i].fst && poi[i].fst <= x2){
			int x = poi[i].fst - x1;
			int y = (x2-x1)/2; 

			if(x <= y){
				if(poi[i].sec <= x) cnt++;
			}
			else{
				x -= y;
				if(x + poi[i].sec <= y) cnt++;
			}
		}
	}
	return cnt;
}

bool cmp(PI a, PI b){
	return a.fst < b.fst;
}

int main() {
	BoostIO;
	int T;  cin>>T;
	while(T--){
		int n, q; cin >> n >> q;

		VPI poi(n);
		for(int i=0; i<n; i++) cin >> poi[i].fst >> poi[i].sec;

		sort(poi.begin(), poi.end(), cmp);
		//print(poi);

		while(q--){
			int x1, x2; cin >> x1 >> x2;
			cout << nop(poi, x1, x2) << " ";
		}
	    cout << endl; 
    }
	return 0;
}
