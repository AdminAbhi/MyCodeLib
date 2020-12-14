//=============================================================================
// @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
//=============================================================================
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
#define BoostIO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)

inline void print(VI &v){ for(int i:v) cout<<i<<" "; cout<<endl;}
inline void print(VLL &v){ for(LL i:v) cout<<i<<" "; cout<<endl;}
inline void print(VVI &v){ for(VI i:v) print(i);}
inline void print(PI p){ cout<<"("<<p.fst<<":"<<p.sec<<"), ";}
inline void print(VPI &P){for(PI i:P) print(i); cout<<endl;}
inline void print(set<int> &s){for(int i:s)cout<<i<<" "; cout<<endl;}
inline void print(map<int,int> m){for(auto i:m) print(i); cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

//=============================================================================
//--------------------------Keep-Calm-and-Code---------------------------------
//=============================================================================








int main() {
	BoostIO;

	ifstream fin;
	ofstream fout;
	fin.open("travel_restrictions_input.txt");
	fout.open("travel_restrictions_output.txt");
	//fin >> x; fout << x;

	int T = 1;
	fin >> T;
	int t = 1;
	while(t <= T){
		int n; fin >> n;
		string inc; fin >> inc;
		string out; fin >> out;

		vector<string> mat(n, string (n, 'N'));
		//for(int i=0; i<n; i++) cout << mat[i] << endl;

		for(int i=0; i<n; i++) mat[i][i] = 'Y';

		for(int i=0; i<n; i++){
			for(int j=i; j<n-1; j++){
				if(inc[j+1] == 'Y' && out[j] == 'Y') mat[i][j+1] = 'Y';
				else break;
			}
			for(int j=i; j>0; j--){
				if(inc[j-1] == 'Y' && out[j] == 'Y') mat[i][j-1] = 'Y';
				else break;
			}
		}
		fout << "Case #" << t << ":" << endl;
		for(int i=0; i<n; i++) fout << mat[i] << endl;
		t++;
    }
    fin.close();
    fout.close();
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
