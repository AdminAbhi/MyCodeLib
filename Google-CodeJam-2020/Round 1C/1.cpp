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

#define dbg(x, y) cout << x << " = " << y << endl

inline void print(auto v){ for(auto i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();


inline void move(PI &p, char c){
	if(c == 'N') p.sec++;
	else if(c == 'S') p.sec--;
	else if(c == 'E') p.fst++;
	else if(c == 'W') p.fst--;
}

int main() {
	BoostIO;
	int T;  cin >> T;
	int t = 1;
	while(t <= T){
		int x = 0;
		int y = 0;

		

		string s;
		int a, b;
		cin >> a >> b >> s;

		if(a == 0 && b == 0){
			cout << "Case #" << t << ": " << 0 << endl;
			t++;
			continue;
		}

		PI p = {a,b};
		
		
		//string res = "IMPOSSIBLE";

		//int n = 15;
		
		//VVI mat(n, VI (n, 0));

		//mat[a][b] = 1; 
		//mat[x][y] = 2;

		int time = 0;
		//bool flag = 0;

		PI goal;
		
		//double mini = INT_MAX;
		int dur = s.length()+1;
		
		for(unsigned int i=0; i<s.length(); i++){

			move(p, s[i]);
			time++;

			int dis = abs(p.fst) + abs(p.sec);

			if(dis <= time) dur = time;
			else if( dis + time < dur){
				dur = dis + time;
			}
		}
		//print(mat);

		if(dur > s.length())
			cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
		else{
			//int tot = goal.fst + goal.sec;
			cout << "Case #" << t << ": " << dur << endl;
		} 

	    t++;
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
