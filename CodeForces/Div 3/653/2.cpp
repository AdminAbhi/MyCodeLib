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


map<int, int> div(int n){
	map<int, int> mp;
	
	while(n % 2 == 0){
		mp[2]++;
		n /= 2;
	}
	while(n % 3 == 0){
		mp[3]++;
		n /= 3;
	}
	
	for(int i = 5; i*i <= n; i += 6){
		while(n % i == 0){
			mp[i]++;
			n /= i;
		}
		while(n % (i+2) == 0){
			mp[i+2]++;
			n /= (i+2);
		}
	}
	if(n != 1) mp[n]++;
	
	return mp;
}


int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		LL n; cin >> n;
		
		map<int, int> di = div(n);
		//print(di);
		
		bool foo = 0;
		int two = 0, three = 0;
		
		for(auto i: di){
			
			if(i.fst == 2) two += i.sec;
			if(i.fst == 3) three += i.sec;
			
			if(i.fst != 2 && i.fst != 3){
				foo = 1;
				break;
			}
		}

		if(foo || (two > three)){
			cout << -1 << endl;
			continue;
		}
		
		int need1 = max(two, three);
		
		int need2 = three - two;
		
		LL step = need2 + need1;
		
		cout << step << endl;
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

