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

int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){

		int n; cin >> n;
		VI arr(n);

		unordered_map<int, int> mp;
		
		int maxd = 0;

		for(int i=0; i<n; i++){
			cin >> arr[i];
			
			mp[arr[i]]++;

			if(mp[arr[i]] > maxd) maxd = mp[arr[i]];
		}
		
		priority_queue<PI> pq;

		for(auto i = mp.begin(); i != mp.end(); i++){
			pq.push(MP(i->sec, i->fst));
		}

		//bool flag = true;
		
		while(!pq.empty()){
			PI p = pq.top();
			//cout << p.fst << " -> "<< p.sec << endl;
			pq.pop();
			if(p.fst - 1 > mp.size()){ 
				cout << mp.size() << endl;
				break;
			}
			else if(p.fst - 1 <= mp.size()){
				if(p.fst == 1 && mp.size() > 1) cout << 1 << endl;
				else cout << p.fst -1 << endl;
				break;
			}
		}
	    //if(flag) cout << 1 << endl;
    }
	return 0;
}
