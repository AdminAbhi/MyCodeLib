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
#define dbg(x, y) cout << x << " = " << y << endl
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI &v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> &s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();


int sol(VI &arr, int n){
	int cnt = 0;
	
	if(n <= 4) return 0;

	int h=0, l=0;
	for(int i=1; i<4; i++){
		if(arr[i] > arr[i-1]) h++;
		else if(arr[i] < arr[i-1]) l++;
	}
	
	int val = 0;
	if(h==0) val = l;
	else if(l==0) val = 3-h;
	else if(l > h) val = 2;
	
	//cout << "val = " << val << endl;
	
	int idx = 1;
	while(idx < n){
		
		if(arr[idx] > arr[idx-1]) val++;
		else if(arr[idx] < arr[idx-1]) val--;
		
		if(val > 0 && val % 4 == 0) cnt++;
		else if(val < 0 && abs(val)%4 == 1) cnt++;
		
		//cout << "val = " << val << endl;
		idx++;
	}
	
	
	return cnt;
}


int main() {
	BoostIO;
	int T;  cin >> T;
	for(int t=1; t<=T; t++){
	    int n; cin >> n;
	    VI arr(n); for(int i=0; i<n; i++) cin >> arr[i];
	    
	    
	    cout << "Case #" << t << ": " << sol(arr, n) << endl;
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
