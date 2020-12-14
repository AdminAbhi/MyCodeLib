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
#define MOD7 1000000007
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

#define MOD 998244353
#define a0 0
#define A1 1


int MI(int a, int m){
    int m0 = m, y = 0, x = 1;
    if (m == 1) return 0;
    while(a > 1){
		  int q = a / m, t = m;
        m = a % m, a = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}

VPI result(char a){
	VPI res(4);
	if(a == '&'){
		res[0].fst = 2; res[0].sec = 4;
		res[1].fst = 0; res[1].sec = 4;
		res[2].fst = 1; res[2].sec = 4;
		res[3].fst = 1; res[3].sec = 4;

		return res;
	}
	if(a == '|'){
		res[0].fst = 0; res[0].sec = 4;
		res[1].fst = 2; res[1].sec = 4;
		res[2].fst = 1; res[2].sec = 4;
		res[3].fst = 1; res[3].sec = 4;

		return res;
	}
	if(a == '^'){
		res[0].fst = 0; res[0].sec = 2;
		res[1].fst = 0; res[1].sec = 2;
		res[2].fst = 0; res[2].sec = 2;
		res[3].fst = 0; res[3].sec = 2;

		return res;
	}
	return res;
}

void newP(VPI &pq, VPI &vp){
	for(int i=0; i<4; i++){
		pq[i].fst += vp[i].fst;
		pq[i].sec += vp[i].sec;
	}
}

int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){

		string s; cin >> s;

		int q = 0;
		for(unsigned int i=0; i<s.length(); i++) if(s[i] == '#') q++;

		if(s.length() == 1){
			int p0 = q, p1 = q, pa = q, pA = q;
			q *= 4;
			q = MI(q, MOD);
			cout << p0*q << " " << p1*q << " " << pa*q << " " << pA*q << endl;
			continue;
		}

		VPI pq(4);
		pq[0].fst = 0; pq[0].sec = 0;
		pq[1].fst = 0; pq[1].sec = 0;
		pq[2].fst = 0; pq[2].sec = 0;
		pq[3].fst = 0; pq[3].sec = 0;
		
		stack<int> st;

		int idx = 0;
		st.push(s[idx++]);
		
		while(!st.empty()){
			if(s[idx] == ')'){
				char a = st.top(); st.pop();
				char b = st.top(); st.pop();
				char c = st.top(); st.pop();
				st.pop();

				newP(pq, result(b));
				
			}
		}
		
   }
	return 0;
}
