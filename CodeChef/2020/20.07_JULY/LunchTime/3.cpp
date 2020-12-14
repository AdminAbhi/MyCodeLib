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


string st(int n){
	string s = "";
	while(n){
		int r = n % 2;
		char c = r + '0';
		s += c;
		n /= 2;
	}
	reverse(s.begin(), s.end());
	return s;
}

LL bc(int a, int b){
	string s1 = st(a);
	string s2 = st(b);

	string s12 = s1 + s2;
	string s21 = s2 + s1;

	//cout << s12 << endl;
	//cout << s21 << endl;
	//cout << "------\n";
	//return 0;
	return abs(stoll(s12, 0, 2) - stoll(s21, 0, 2));
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		VI arr(n); for(int i=0; i<n; i++) cin >> arr[i];

		LL gmax = 0;

		if(n <= 100){
			for(int i=0; i<n; i++){
				for(int j=i+1; j<n; j++){
					gmax = max(gmax, bc(arr[i], arr[j]));
				}
			}
			//cout << gmax << endl;
		}

			sort(arr.begin(), arr.end());

			for(int i=0; i<n; i++) gmax = max(gmax, bc(arr[i], arr[n-1]));
			cout << gmax << endl;

    }

	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
