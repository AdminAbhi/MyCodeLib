//==============================================================================
// @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
//==============================================================================
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef vector<VI> VVI;
typedef pair<int,int> PI;
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
#define BoostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl;}
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl;}
inline void print(VVI &v){ for(VI i:v) print(i);}
inline void print(PI p){ cout<<"("<<p.fst<<":"<<p.sec<<"), ";}
inline void print(VPI &P){ for(PI i:P) print(i); cout<<endl;}
inline void print(set<int> &s){ for(int i:s)cout<<i<<" "; cout<<endl;}
inline void print(map<int,int> &m){for(auto i:m) print(i); cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

//==============================================================================
//--------------------------Keep-Calm-and-Code----------------------------------
//==============================================================================

struct node{
	int pre=0, pos=0, val=0;
};


inline int incSub(VI &arr, vector<VPI> &hmat, int l, int r, int n){
	VI temp(n);
	if(l<=r){
		if(arr[l] < hmat[l][l]) return -1;
		
		for(int i=l; i<=r; i++){
			temp[i] = arr[i] <= arr[l]? arr[i]: -1;
		}
		for(int i=l+1; i<=r; i++){
			for(int j=l; j<i; j++){
				if(arr[i] >= arr[j] && arr[j] >= hmat[i][j].sec
									&& arr[i] >= hmat[i][j].sec){
					
					if(abs(i-j) > 1 && check()) continue;
					 
					temp[i] = max(temp[i], temp[j] + arr[i]);
				}
			}
		}
		int res = 0;
		for(int i=l; i<=r; i++) res = max(res, temp[i]);
		return res;
	}
	else{
		if(arr[r] < hmat[r][r]) return -1;
		
		for(int i=l; i>=r; i--){
			temp[i] = arr[i] <= arr[l]? arr[i]: -1;
		}
		for(int i=l-1; i>=r; i--){
			for(int j=l; j>i; j++){
				if(arr[i] >= arr[j] && arr[j] >= hmat[i][j]
									&& arr[i] >= hmat[i][j]){
					temp[i] = max(temp[i], temp[j] + arr[i]);
				}
			}
		}
		int res = 0;
		for(int i=l; i>=r; i--) res = max(res, temp[i]);
		return res;
	}
	
}


inline int decSub(vector<node> &arr, int l, int r){
	VI temp;
	vector<node> a;
	int n;
	if(l<=r){
		n = r-l+1;
		for(int i=l; i<=r; i++){
			a.PB(arr[i]);
			temp.PB(arr[i].val);
		}
	}
	else{
		n = l-r+1;
		int idx = 0;
		for(int i=l; i>=r; i--){
			a.PB(arr[i]);
			swap(a[idx].pre, a[idx].pos);
			temp.PB(arr[i].val);
			idx++;
		}
	}
	for(int i=1; i<n; i++){
		for(int j=0; j<i; j++){
			if(a[i].val <= a[j].val && a[i].pre <= a[j].val){
				temp[i] = max(temp[i], temp[j] + a[i].val);
			}
		}
	}
	int res = 0;
	for(int i=0; i<n; i++) res = max(res, temp[i]);
	return res;
}


int main() {
	BoostIO;
	
	int n, q; cin >> n >> q;
	VI h(n), a(n);
	vector<node> arr(n);
	
	for(int i=0; i<n; i++) cin >> h[i];
	
	vector<VPI> hmat(n, VPI (n));
	for(int i=0; i<n; i++){
		for(int j=i; j<n; j++){
			if(i==j) hmat[i][j] = {j+1, h[i]};
			else{
				hmat[i][j] = {j+1, max(hmat[i][j-1].sec, h[j])};
				hmat[j][i] = hmat[i][j];
			}
		}
	}
	for(int i=0; i<n; i++) print(hmat[i]);
	
	for(int i=0; i<n; i++){
		cin >> a[i];
		if(i==0){
			arr[i].pre = INT_MAX;
			arr[i].val = a[i];
			arr[i].pos = n > 1? h[i+1]: INT_MAX;
		}
		else if(i == n-1){
			arr[i].pre = h[i-1];
			arr[i].val = a[i];
			arr[i].pos = INT_MAX;
		}
		else{
			arr[i].pre = h[i-1];
			arr[i].val = a[i];
			arr[i].pos = h[i+1];
		}
	} 
	while(q--){
		int type; cin >> type;
		if(type == 1){
			int b, k; cin >> b >> k;
			a[b-1] = k;
			arr[b-1].val = k;
		}
		else{
			int b, c; cin >> b >> c;
			//cout << max(incSub(a, b-1, c-1, hmat), 
			//			decSub(a, b-1, c-1, hmat)) << endl;
		}
	}
    
	return 0;
}


//===============================================================================
//-------------------------------------------------------------------------------
//    ##     ######   ##   ##  ####   #####   ##   ##     ##     ##   ##  ######   
//   ####    ##   ##  ##   ##   ##   ##   ##  ##   ##    ####    ##  ##   ##         
//  ##  ##   ##   ##  ##   ##   ##   ##       ##   ##   ##  ##   ## ##    ##         
// ##    ##  ######   #######   ##    #####   #######  ##    ##  ####     ######     
// ########  ##   ##  ##   ##   ##        ##  ##   ##  ########  ## ##    ##         
// ##    ##  ##   ##  ##   ##   ##   ##   ##  ##   ##  ##    ##  ##  ##   ##     
// ##    ##  ######   ##   ##  ####   #####   ##   ##  ##    ##  ##   ##  ######   
//-------------------------------------------------------------------------------
//===============================================================================
