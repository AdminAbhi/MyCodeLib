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




void solve(int n, int x, vector<int> &seq){
    vector<deque<int>> best(32);
    for(int i=n-1; i>=0; i--){
        bitset<32> num(seq[i]);
        for(int p=31; p>=0; p--){
            if(num[p] == 1) best[p].push_front(i);
        }
    }
    
    for(int i=0; i<n && x > 0; i++){
        
        for(int j=0; j<32; j++){
            if(best[j].size() > 0 && best[j].front() == i) best[j].pop_front();
        }
        bitset<32> curr(seq[i]);
        
        if(seq[i] > 0) for(int p=31; p>=0 && x > 0; p--){
            if(curr[p] == 1 && best[p].size() > 0){
                int idx = best[p].front(); best[p].pop_front();
                bitset<32> next(seq[idx]);
                curr.flip(p);
                next.flip(p);
                seq[idx] = next.to_ulong();
                x--;
            }
            else if(i != n-1 && curr[p] == 1){
                bitset<32> last(seq[n-1]);
                curr.flip(p);
                last.flip(p);
                seq[n-1] = last.to_ulong();
                best[p].push_back(n-1);
                x--;
            }
        }
        seq[i] = curr.to_ulong();
    }
    
    if(n == 2 && x % 2 == 1){
        bitset<32> last(seq[n-1]);
        bitset<32> sec_last(seq[n-2]);
        last.flip(0);
        sec_last.flip(0);
        seq[n-2] = sec_last.to_ulong();
        seq[n-1] = last.to_ulong();
    }
    
    for(auto i: seq) cout << i << " ";
    cout << endl;
}

int main() {
    BoostIO;
	int T = 1; 
	cin >> T;
	while(T--){
	    int n, x; cin >> n >> x;
	    vector<int> seq(n);
	    for(int i=0; i<n; i++) cin >> seq[i];
	    
	    solve(n, x, seq);
	}
	return 0;
}


//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
