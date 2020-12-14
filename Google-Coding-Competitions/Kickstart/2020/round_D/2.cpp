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
	
	VI v(n, 0);
	VI nv(n, 0);
	
	for(int i=1; i<n; i++){
		if(arr[i] > arr[i-1]) v[i] = 1;
		else if(arr[i] == arr[i-1]) v[i] = 0;
		else v[i] = -1;
	}
	
	
	if(n <= 4) return 0;
	
	VI ap = {0, 0, 0, 0};
	
	int bi=1, h=0, l=0;
	
	for(int i=0; i<4; i++){
		if(arr[i] > arr[0]) h++;
		else if(arr[i] < arr[0]) l++;		
	}
	
	if(h==0) bi = l;
	else if(l==0) bi = 3 -h;
	else if(l > h) bi = 2;
	
	int idx = 4;
	int base = arr[3];
	
	int temp;
	for(int i=0; i<4; i++){
		temp = bi;
		if(arr[i] > arr[0]) bi++;
		else if(arr[i] < arr[0]) bi--;
		
		if(i>0 && bi > temp) nv[i] = 1;
		else if(i > 0 && bi < temp) nv[i] = -1;
	}
	
	//cout << "h=" << h << " l=" << l << " bi=" << bi << endl;
	
	while(idx < n){
		//int base = arr[idx];
		h=0;
		l=0;
		for(int i=idx; i<min(idx+4, n); i++){
			if(arr[i] > base) h++;
			else if(arr[i] < base) l++;
			
		}
		
		if(bi + h > 3 || bi - l < 0){
			cnt++;
			h=0;
			l=0;
			for(int i=idx; i<min(idx+4, n); i++){
				if(arr[i] > arr[idx]) h++;
				else if(arr[i] < arr[idx]) l++;
			
			}
			int b = 1;
			if(h==0) b = l;
			else if(l==0) b = 3 -h;
			else if(l > h) b = 2;
			
			bi = b;
			for(int i=idx; i<min(idx+4, n); i++){
				temp = bi;
				if(arr[i] > arr[idx]) bi++;
				else if(arr[i] < arr[idx]) bi--;
				
				if(bi > temp) nv[i] = 1;
				else if(bi < temp) nv[i] = -1;
			}
		}	
		else{
			for(int i=idx; i<min(idx+4, n); i++){
				temp = bi;
				if(arr[i] > base) bi++;
				else if(arr[i] < base) bi--;
				
				if(bi > temp) nv[i] = 1;
				else if(bi < temp) nv[i] = -1;
			}
		}
		//cout << "h=" << h << " l=" << l << " bi=" << bi << endl;
		
		base = arr[idx+3];
		idx+=4;
	}
	int res = 0;
	for(int i=0; i<n; i++) if(v[i] != nv[i]) res++;
	return res;
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
