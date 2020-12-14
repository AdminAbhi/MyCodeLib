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


bool cmp(pair<LL, LL> &a, pair<LL, LL> &b){
	LL one = 1;
	LL ap = (one << a.sec);
	LL bp = (one << b.sec);
	
	return (a.fst * (ap)) > (b.fst*(bp));
	
	//return a.fst > b.fst;
}


int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		int n, k; cin >> n >> k;
		VLL arr(n);
		for(int i=0; i<n; i++){
			cin >> arr[i];
		}
		vector<pair<LL, LL>> num(32);
		for(int i=0; i<32; i++){
			num[i].fst = 0;
			num[i].sec = i;
		}
		
		
		for(int i=0; i<n; i++){
			int idx = 0;
			LL a = arr[i];
			while(a){
				if(a & 1){
					num[idx].fst++;
				} 
				a >>= 1;
				idx++;
			}
		}
		//print(arr);
		
		//print(num);
		
		//for(int i=0; i<10; i++) cout << "(" << num[i].fst << "|" << num[i].sec << "), ";
		//cout << endl;
		
		sort(num.begin(), num.end(), cmp);
		
		//for(int i=0; i<10; i++) cout << "(" << num[i].fst << "|" << num[i].sec << "), ";
		//cout << endl;
		
		//print(num);
		
		LL x = 0;
		
		for(int i=0; i<k; i++){
			LL bit = 1;
			x |= (bit << num[i].sec);
			//bitset<32>xx(x);
			//cout << xx << endl;
		}
		
		cout << x << endl;
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

