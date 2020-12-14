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

VVI get_goal(){
	VVI goal(8);
	for(int i=0; i<8; i++){
		goal[i].resize(8,0);
		for(int j=0; j<8; j++){
			if(i%2 == 0 && j%2 !=0) goal[i][j] = 1;
			else if(i%2 != 0 && j%2 ==0) goal[i][j] = 1; 
		}
	}
	return goal;
}

bool is_Goal(VVI a, VVI g){
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			if(a[i][j] != g[i][j]) return false;
		}
	}
	return true;
}

int main() {
	BoostIO;
	int T;  cin >> T;
	VVI goal = get_goal();
	//print(goal);
	cout << endl;
	while(T--){
		VVI board(8);
		for(int i=0; i<8; i++) board[i].resize(8,0);
		int r,c; cin >> r >> c;
		board[r-1][c-1] = 1;
	   //print(board);
	   //cout << is_Goal(board, goal);
	   
	   
	}
	return 0;
}
