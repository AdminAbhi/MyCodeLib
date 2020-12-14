//==============================================================================
// @abhi_admin     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
//==============================================================================
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
#define dbg(x, y) cout << x << " = " << y << endl
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

//==============================================================================
//--------------------------Keep-Calm-and-Code----------------------------------
//==============================================================================









int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
	    LL n; cin >> n;
	    
	    VLL a(n), b(n);
	    LL gmin = INT_MAX;
	    
	    umap<LL, LL> ma, mb, mg;
	    
	    for(LL i=0; i<n; i++){
			cin >> a[i];
			gmin = min(gmin, a[i]);
			ma[a[i]]++;
			mg[a[i]]++;
		} 
	    for(LL i=0; i<n; i++){
			cin >> b[i];
			gmin = min(gmin, b[i]);
			mb[b[i]]++;
			mg[b[i]]++;
	    }
	    
	    bool foo = 0;
		for(auto i: mg){
			if(i.sec % 2 != 0){
				foo = 1;
				break;
			}
			else mg[i.fst] /= 2;
		}
		if(foo){
			cout << -1 << endl;
			continue;
		}
		
		VLL la, lb;
		
		for(auto i: mg){
			if(ma.find(i.fst) != ma.end()){
				if(ma[i.fst] > i.sec){
					for(LL j=0; j<ma[i.fst]-i.sec; j++)
						la.PB(i.fst);
				}
				else{
					for(LL j=0; j<i.sec-ma[i.fst]; j++)
						lb.PB(i.fst);
				}
			}
			else{
				for(LL j=0; j<i.sec; j++) lb.PB(i.fst);
			}
		
		}
	
		
		priority_queue<LL, VLL, greater<LL>> qa;
		priority_queue<LL, VLL, greater<LL>> qb;
			
		for(LL i=0; i<la.size(); i++){
			qa.push(la[i]);
			qb.push(lb[i]);
		}
		LL cost = 0;
		for(LL i=0; i<la.size(); i++){
			LL aa = qa.top();
			LL bb = qb.top();
			if(min(aa, bb) < 2*gmin){
				if(aa < bb){
					cost += aa;
					qa.pop();
				}
				else{
					cost += bb;
					qb.pop();
				}
			}
			else{
				cost += 2*gmin;
				qa.pop();
				qb.pop();
			}
				
		}
		cout << cost << endl;
    }
	return 0;
}


//===============================================================================
//-------------------------------------------------------------------------------
//    ##     ######   ##   ##  ####   #####   ##   ##     ##     ##   ##  ######   
//   ####    ##   ##  ##   ##   ##   ##   ##  ##   ##    ####    ##  ##   ##         
//  ##  ##   ##   ##  ##   ##   ##   ##       ##   ##   ##  ##   ## ##    ##         
// ##    ##  ######   #######   ##    #####   #######  ##    ##  ####     ######     
// ########  ##   ##  ##   ##   ##        ##  ##   ##  ########  ## ##    ##         
// ##    ##  ##   ##  ##   ##   ##   ##   ##  ##   ##  ##    ##  ##  ##   ##     
// ##    ##  ######   ##   ##  ####   #####   ##   ##  ##    ##  ##   ##  ######   
//-------------------------------------------------------------------------------
//===============================================================================
