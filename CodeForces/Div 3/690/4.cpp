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




class cmp{
	public:
	int operator()(PI a, PI b){
		return a.fst >= b.fst;
	}
};



int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	while(T--){
		int n; cin >> n;
		VI arr(n);
		LL sum = 0; 
		priority_queue<PI, VPI, cmp> que;
		
		for(int i=0; i<n; i++){
			cin >> arr[i];
			sum += arr[i];
			que.push({arr[i], i});
		} 
		int step = 0;
		while(que.size() > 0){
			auto p = que.top(); que.pop();
			//cout << p.fst << " ";
			
			if(p.fst < arr[p.sec]){
				que.push({arr[p.sec], p.sec});
				continue;
			} 
			
			if(p.fst * ((LL)que.size() + 1) == sum) break;
			
			int idx = -1;
			if(p.sec > 0 && p.sec < n-1){
				int l = p.sec-1;
				int r = p.sec+1;
				while(l >= 0 && arr[l] == -1) l--;
				while(r < n && arr[r] == -1) r++; 
				if(l >= 0 && l < n && r >= 0 && r < n){
					if(arr[l] <= arr[r]) idx = l;
					else idx = r;
				}
				else if(l >= 0 && l < n){
					idx = l;
				}
				else if(r >= 0 && r < n){
					idx = r;
				}
			}
			else if(p.sec == 0){
				idx = 1;
				while(idx < n && arr[idx] == -1) idx++;
				
			}
			else{
				idx = n-2;
				while(idx >= 0 && arr[idx] == -1) idx--;
				
			}
			if(idx == -1 || arr[idx] == -1) continue;
			step++;
			arr[idx] += arr[p.sec];
			arr[p.sec] = -1; 
			//print(arr);
		}
	
		//print(arr);
		cout << step << endl;
		
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================
