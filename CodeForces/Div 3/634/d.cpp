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

char check(string[] &s, int i, unordered_map<char, int> mp){
	int idx = i % 3;

}

int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		string s[9];
		for(int i=0; i<9; i++) cin >> s[i];

		for(int i=0; i<9; i++){

			unordered_map<char, int> mp;
			//mp[s[i][i]]++;
			
			for(int j=0; j<9; j++){
				if(i != j) mp[s[i][j]]++;
			}
			for(int j=0; j<9; j++){
				if(i != j) mp[s[j][i]]++;
			}
			for(auto j = mp.begin(); j!= mp.end(); j++){
				if(j->sec >= 2){
					s[i][i] = j->fst;
					break;
				} 
			}
			//int c = 10 - (s[i][i] - '0');
			//s[i][i] = '0' + c;
		}
		//cout << "------------\n";
		for(int i=0; i<9; i++) cout << s[i] << endl;
    }
	return 0;
}
