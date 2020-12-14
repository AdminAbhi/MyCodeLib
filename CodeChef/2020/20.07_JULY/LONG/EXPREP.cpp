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

LL M = 998244353;

inline LL modI(LL aa, LL mm){ 
    LL mm0 = mm, yy = 0, xx = 1; 
    if (mm == 1) return 0; 
    while(aa > 1){ 
        LL qq = aa / mm; 
        LL tt = mm; 
        mm = aa % mm;
        aa = tt; 
        tt = yy; 
        yy = xx - qq * yy; 
        xx = tt; 
    } 
    if (xx < 0) xx += mm0; 
    return xx;
}


LL sol(string s, VLL &ch, int n){
    VLL hash(n+1, 0);
    for(LL i=1; i<=n; i++) hash[i] = hash[i-1] + ch[s[i-1] - 'a'];
    //print(hash);
    
    LL tot_cost = 0;
    
    for(LL k=1; k<=n; k++){
        for(LL i=0; i<=n-k; i++){
            string ss = s.substr(i, k);
            
            LL cost = hash[i+k] - hash[i];
            LL pl = 1;
            
            //if(ss.length()>2)
            while(pl <= k/2){
                if(ss.substr(0,pl) == ss.substr(k-pl, pl)){
					LL l = ss.length()-pl;
					cost += hash[i+k-pl] - hash[i];
					//cout << ss.substr(0,pl) << endl;
					
					LL li = pl;
					
					while(li <= l/2){
						if(l%li == 0){
							bool foo = 1;
							string sss = ss.substr(0,li);
							
							for(LL x=0,loop = l/li; loop>0; loop--, x += li){
								if(sss != ss.substr(x, li)){
									foo = 0;
									break;
								}
							}
							if(foo){
								cost += hash[i+li] - hash[i];
								//cout << s.substr(i,li) << endl;
							}
						}
						li++;
					}
					
                }
                pl++;
            }
			//cout << ss << " -> " << cost << endl;
            tot_cost += cost;
            
        }
    }
    return tot_cost;
}



int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
	    string s; cin >> s;
	    VLL ch(26); for(LL i=0; i<26; i++) cin >> ch[i];
	    
	    LL n = s.length();
	    
	    LL p = sol(s, ch, n);
	    //cout << p << endl;
	    
	    LL q = (n*(n+1))/2;
	    LL gcd = __gcd(p,q);
	    
	    p = p/gcd;
	    q = q/gcd;
	    
	    LL res = (p*modI(q, M)) % M;
	    
	    cout << res << endl;
	   //cout << (5*modI(2, M))%M << endl;
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
