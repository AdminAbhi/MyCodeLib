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




void move(int &player, VVI &adj, map<PI, int> &mp1, map<int, PI> &mp2, VVI & room, int ri, int pi, int r, int p){
	if(ri < 0 || ri > 1 || pi < 0 ) return;
	else if(ri == 0 && pi > 0) return;
	else if(ri == 1 && pi > 2) return;

	if(ri == r && pi == p) return;

	for(int i=0; i<adj[mp[{ri, pi}]].size(); i++){
		PI p = mp2[adj[mp[{ri, pi}]][i];
		if(room[p.fst][p.sec] == 1) continue;
		player++;
		room[p.fst][p.sec] = 1;
		move(player, adj, mp1, mp2, room, ri, pi, r ,p);

	}
}



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	int t = 1;
	while(t <= T){

		int s, r1, p1, r2, p2, c;
		cin >> s >> r1 >> p1 >> r2 >> p2 >> c;


		map<PI, int> mp1;
		mp1[{0,0}] = 0;
		mp1[{1,0}] = 1;
		mp1[{1,1}] = 2;
		mp1[{1,2}] = 3;

		map<int, PI> mp2;
		mp2[0] = {0,0};
		mp2[1] = {1,0};
		mp2[2] = {1,1};
		mp2[3] = {1,2};

		VVI adj(4);

		adj[0].PB(2); adj[1].PB(2); adj[3].PB(2);

		adj[2].PB(0); adj[2].PB(1); adj[2].PB(3);


		VVI room(2);
		room[0].resize(1, 0);
		room[1].resize(3, 0);

		VPI blk(c);
		for(int i=0; i<c; i++){
			cin >> blk[i].fst >> blk[i].sec;
			blk[i].fst--;
			blk[i].sec--;
			room[blk[i].fst][blk[i].sec] = 1;
		}


		int A = 0, B = 0;

		move(A, adj, mp1, mp2, room, r1, p1, r2, p2);
		//move(B, adj, mp1, mp2, room, r2, p2, r1, p1);

		cout << "Case #" << t << ": ";
		cout << A << endl;

		t++;
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

