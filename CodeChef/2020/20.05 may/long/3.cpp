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


#define MBIT 60



int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		unsigned long long x, y, l, r; cin >> x >> y >> l >> r;
            
        if(x != 0 && y != 0){
            LL z = x|y;
            if(l <= z && z <= r) cout << z << endl;
            else if(z > r){
                //cout << bitset<32>(z) << endl;
                //cout << bitset<32>(r) << endl;

                int i = 60;
                while(!(r & (LL)1<<i)){
                    z &= ((LL)1<<i) - 1;
                    i--;
                }
                //cout << bitset<32>(z) << endl;
                
                if(l <= z && z <= r) cout << z << endl;
                else{
                    LL temp = LONG_MAX;  //cout << "temp = " << bitset<32>(temp) << endl;
                    LL sz = (x & l) * (y & l) > (x & r) * (y & r) ? l : r;
                    LL maxv = (x & sz) * (y & sz);
                    for(int j=0; j<=i; j++){
                        for(int k=0; k<=j; k++){
                            LL zz = temp ^ ((LL)1<<j); //cout << "zz = " << bitset<32>(zz) << endl; 
                            if(k != j)
                                zz = zz ^ ((LL)1<<k);
                            LL z1 = z & zz;     //cout << j <<" "<< k << " z1 = " << bitset<32>(z1) << endl;
                            
                            if(l > z1 || z1 >= r) continue;
                            
                            LL res = (x & z1) * (y & z1);
                            
                            if(res > maxv){
                                maxv = res;
                                sz = z1;
                            }
                            else if(res == maxv && z1 < sz){
                                sz = z1;
                            }
                            
                        }
                    }    
                    //cout << "sz = " << bitset<32>(sz) << endl;
                    cout << sz << endl;
                }
                
            }
            else{
                cout << z << endl;
            }
        }
		else cout << 0 << endl;
		
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
