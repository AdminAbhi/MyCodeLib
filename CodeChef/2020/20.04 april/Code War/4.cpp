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
#define MOD7 1000000000000
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

map<int, int> getFact(int a){
	map<int, int> mp;
	
	while(a % 2 == 0){
		mp[2]++;
		a /= 2;
	}
	while(a % 3 == 0){
		mp[3]++;
		a /= 3;
	}
	for(int i = 5; i * i <= a; i++){
		if(a % i == 0){
			mp[i]++;
			a /= i;
		}
	}
	if(a != 1) mp[a]++;
	
	return mp;
}

void print(map<int, int> mp){
	for(auto i = mp.begin(); i != mp.end(); i++){
		
		cout << i->fst << " -> " << i->sec << endl;
	}
}

int main() {
	BoostIO;
	int n; cin >> n;
	VI arr(n);

	//int lcm = 1;

	map<int, int> mp;
	
	for(int i=0; i<n; i++){
		cin >> arr[i];
		//print(getFact(arr[i]));
		//cout << "---------\n";

		map<int, int> m;
		m = getFact(arr[i]);

		for(auto i = m.begin(); i != m.end(); i++){
			if(mp.find(i->fst) != mp.end()){
				mp[i->fst] = max(mp[i->fst], m[i->fst]);
			}
			else mp[i->fst] = m[i->fst];
		}

	}

	//print(mp);
	
	LL lcm = 1;
	for(auto i : mp){
		LL x = pow(i.fst, i.sec);
		lcm = (lcm * x) % MOD7;
	}
	
	cout << lcm << endl;
	
	return 0;
}
