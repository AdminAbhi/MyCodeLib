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

string dfs(string &s, int &x, int &y, int xi, int yi, int &lim, int d){

	if(abs(xi) > lim || abs(yi) > lim) return "IMPOSSIBLE";

	if(xi == x && yi == y) return s;

	string res;

	//E
	s.push_back('E');
	res = dfs(s, x, y, xi + pow(2, d), yi, lim, d+1);
	if( res != "IMPOSSIBLE") return res;
	s.pop_back();
	
	//N
	s.push_back('N');
	res = dfs(s, x, y, xi, yi+ pow(2, d), lim, d+1);
	if( res != "IMPOSSIBLE") return res;
	s.pop_back();
	
	//W
	s.push_back('W');
	res = dfs(s, x, y, xi - pow(2, d), yi, lim, d+1);
	if( res != "IMPOSSIBLE") return res;
	s.pop_back();
	
	//S
	s.push_back('S');
	res = dfs(s, x, y, xi, yi- pow(2, d), lim, d+1);
	if( res != "IMPOSSIBLE") return res;
	s.pop_back();
	
	return res;
}


int main() {
	BoostIO;
	int T;  cin >> T;
	int t = 1;
	while(t <= T){
		int x, y; cin >> x >> y;

		int lim = max(abs(x), abs(y));
		
		string s = "";
		//int d = 0;
		string res = "IMPOSSIBLE";

		queue<pair<PI, string>> q;
		map<PI, int> mp;
		
		q.push({{0,0}, ""});
		mp[{0,0}]++;

		while(!q.empty()){
			pair<PI, string> p = q.front();
			q.pop();

			int xi  = p.fst.fst;
			int yi = p.fst.sec;
			string ss = p.sec;
			int d = p.sec.length();

			if(pow(2,d)/4 > lim) continue;
			
			if(xi == x && yi == y){
				res = ss;
				break;
			} 
			int p2 = pow(2, d);
			
			if(mp.find({xi + p2, yi}) == mp.end()) 
				q.push({{xi + p2, yi}, ss + "E"});

			if(mp.find({xi , yi + p2}) == mp.end())
				q.push({{xi , yi + p2}, ss + "N"});

			if(mp.find({xi - p2, yi}) == mp.end())
				q.push({{xi - p2, yi}, ss + "W"});

			if(mp.find({xi , yi - p2}) == mp.end())
				q.push({{xi , yi - p2}, ss + "S"});
		}
		
		//string res = dfs(s, x, y, 0, 0, lim, d);
		
		cout << "Case #" << t << ": " << res << endl;
	    t++;
    }
	return 0;
}
