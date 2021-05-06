//=============================================================================
// @abhi_admin     linkedin.com/in/adminabhi     Email: abhiavisekkr@gmail.com
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
inline void print(map<int,int> &m){for(auto i:m) print(i); cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

LL power(LL a, LL b, LL MOD){
    LL res = 1;
    while(b){
        if(b%2) res = (res*a) % MOD;
        a = (a*a) % MOD;
        b /= 2;
    }return res;
}
LL iMOD(LL a, LL p){
    return power(a, p-2, p);
}
//=============================================================================
//--------------------------Keep-Calm-and-Code---------------------------------
//=============================================================================


string next_str(string s, int il){
	LL iv = stoll(s.substr(0, il));
	string res = "";
	while(res.size() + il <= s.size()){
		string ts = to_string(iv++);
		res += ts;
		LL nv = stoll(ts) + 1;
		string ns = to_string(nv);
		il = ns.size();
	}
}

void sol(){
    string s; cin >> s;
	int il = 1;
    for(int li = 1; li < min(10, int(s.size() / 2)); li++){
		bool foo = 0;
		LL idx = 0, l = li;
		
		LL iv = stoll(s.substr(0, l));

		bool match = 1;
		
		while(idx + l <= s.size()){
			string cv = s.substr(idx, l);
			if(stoll(cv) != iv){
				il = li;
				match = 0;
				break;
			}
			idx += l;
			iv++;
			string nv = to_string(iv);
			if(nv.size() != cv.size()) l++;
		}
		if(!match){
			il = li;
		}
		else if(idx >= s.size()){
			il = li;
			break;
		}
	}
    string res = next_str(s, il);
    
    while(stoll(res) < stoll(s)){
		s = to_string(stoll(s.substr(0, il)) + 1) + s.substr(il);
		res = next_str(s, il);
	}
    
    cout << res << endl;
}

int main() {
	BoostIO;
	int T; cin >> T;
	int t = 1;
	while(t <= T){
	    cout << "Case #" << t++ << ": ";
	    sol();
	}
	return 0;
}





//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
