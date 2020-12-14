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

#define dbg(x, y) cout << x << " = " << y << endl

inline void print(PI p){ cout << "{" << p.fst << ", " << p.sec <<"}, "<<endl;}
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

bool isSorted(VI v){
	for(unsigned int i=0; i<v.size()-1; i++){
		if(v[i] > v[i+1]) return 0;
	}
	return 1;
}

int find_p(VI &arr, int e){
    if(arr[e]<0) return e;
    else{
        int p = find_p(arr, arr[e]);
        arr[e]=p;
        return p;
    }
}
bool union_xy(VI &arr, int x, int y){
    int set1 = find_p(arr,x);
    int set2 = find_p(arr,y);
    if(set1 == set2) return 0;
    else {
        arr[set1] += arr[set2];
        arr[set2]=set1;
        return 1;
    }
}

int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		int n, m; cin >> n >> m;
		VI arr(n);
		for(int i=0; i<n; i++) cin >> arr[i];

		VI hash(n,-1);
		//for(int i=0; i<n; i++) hash[i] = i;
		
		for(int i=0; i<m; i++){
			int x, y; cin >> x >> y;
			
			//if(x > y) swap(x,y);

			union_xy(hash, x-1, y-1);

			//if(arr[x-1] > arr[y-1]) swap(arr[x-1], arr[y-1]);
		}
	
		int cnt = 0;
		
		if(isSorted(arr)){
			cout << cnt << endl;
			continue;
		}

		for(int i=0; i<n-1; i++){
			int pos = i;
			for(int j = i+1; j<n; j++){
				if(arr[j] < arr[pos]) pos = j;
			}
			if(pos != i){
				swap(arr[i], arr[pos]);
				
				if(find_p(hash, i) != find_p(hash, pos)) cnt++;
			} 
		}
		cout << cnt << endl;
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
