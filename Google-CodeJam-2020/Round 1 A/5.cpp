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


VI rot(VI v){
	int l = v.size();
	int a = v[l-1];
	for(int i=l-1; i>0; i--) v[i] = v[i-1];
	v[0] = a;
	return v;
}

int main() {
	BoostIO;
	int T;  cin>>T;
	int t=1;
	while(t <= T){
		string res = "";
		
		int n, k; cin >> n >> k;
		int sum = (n*(n+1))/2;
		
		if(k % n == 0 || (k == sum && (n % 2 != 0))){
			VI arr(n);
			int x = k/n;
			arr[0] = x++;
			for(int i=1; i<n; i++){
				arr[i] = x++;
				if(x > n) x = 1;
			} 
			cout << "Case #" << t << ": " << "POSSIBLE" << endl;
			
			for(int i=0; i<n; i++){
				print(arr);
				arr = rot(arr);
			}
			
		}
		else cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
	
		t++;
   }
	return 0;
}
