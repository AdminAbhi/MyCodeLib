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
#define MOD 1000000000
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

PI move(string s){
	pair<int, int> p;
	for(unsigned int i=0; i<s.length(); i++){
		char c = s[i];
		if(c == 'E'){
			p.sec += 1;
		}
		if(c == 'W'){
			p.sec -= 1;
		}
		if(c == 'N'){
			p.fst -= 1;
		}
		if(c == 'S'){
			p.fst += 1;
		}
	}
	return p;
}

string str_n(string s, int n){
	string res = "";
	for(int i=0; i<n; i++)
		res += s;
	return res;
}

string dfs(string &s, int &i, int mul){
	string res = "";
	if(i > s.length()) return res;

	if(s[i] > '9'){
		while(i < s.length() && s[i] > '9') res += s[i++];
		return res;
		
	}
	else{
		int a = s[i] - '0'; i += 2;
		res += dfs(s, i, a);
		return str_n(res, mul);
	}
	return "..";
}


int main() {
	BoostIO;
	int T;  cin >> T;
	int t = 1;
	while(t <= T){
		string s; cin >> s;
		int i = 0;
		string res = dfs(s, i, 1);
		
	    cout << "Case #" << t << ": " << res << endl;
	    t++;
    }
	return 0;
}
