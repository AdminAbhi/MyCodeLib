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


//abacaba

bool check(string s){
    if(s[0] == 'a' || s[0] == '?'){
        if(s[1] == 'b' || s[1] == '?'){
            if(s[2] == 'a' || s[2] == '?'){
                if(s[3] == 'c' || s[3] == '?'){
                    if(s[4] == 'a' || s[4] == '?'){
						if(s[5] == 'b' || s[5] == '?'){
							if(s[6] == 'a' || s[6] == '?'){
								return 1;
							}
							return 0;
						}
						return 0;
					}
					return 0;
				}
                return 0;
            }
            return 0;
        }
        return 0;
    }
	return 0;
}


void sol(string  s, int n){
	if(n < 7){
		cout << "No" << endl;
		return;
	}
	int exist = 0;
	for(int i=0; i<n-6; i++){
			if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'a' && s[i+3] == 'c'
				&& s[i+4] == 'a' && s[i+5] == 'b' && s[i+6] == 'a' ){
				exist++;
			}
	}
	if(exist == 1){
		for(int i=0; i<n; i++){
			if(s[i] == '?') s[i] = 'd';
		}
		cout << "Yes" << endl;
		cout << s << endl;
		return;
	}
	else if(exist > 1){
		cout << "No" << endl;
		return;
	}

	bool foo = 1;

	for(int i=0; i<n-6; i++){
		if(check(s.substr(i, 7))){
			s[i] = 'a';
			s[i+1] = 'b';
			s[i+2] = 'a';
			s[i+3] = 'c';
			s[i+4] = 'a';
			s[i+5] = 'b';
			s[i+6] = 'a';
			foo = 0;
			break;
		}
	}
	if(foo){
		cout << "No" << endl;
		return;
	}
	exist = 0;
	for(int i=0; i<n-6; i++){
			if(s[i] == 'a' && s[i+1] == 'b' && s[i+2] == 'a' && s[i+3] == 'c'
				&& s[i+4] == 'a' && s[i+5] == 'b' && s[i+6] == 'a' ){
				exist++;
			}
	}
	if(exist > 1){
		cout << "No" << endl;
		return;
	}
	for(int i; i<n; i++){
		if(s[i] == '?') s[i] = 'd';
	}

	cout << "Yes" << endl;
	cout << s << endl;
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		string s; cin >> s;

		sol(s, n);


    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
