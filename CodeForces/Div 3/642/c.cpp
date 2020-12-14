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
 
inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}
inline void print(set<int> s){for(auto i:s) cout << i <<" "; cout << endl;}
void print(map<int,int>m){for(auto i:m)cout<<i.fst<<":"<<i.sec<<", ";cout<<endl;}
 
// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();
 
 
 
 
 
int main() {
    BoostIO;
    int T;  cin >> T;
    while(T--){
        LL n; cin >> n;
        
        LL mov = 0;
        VI arr(n/2+1, 0);
 
        int x = 1;
        for(LL i=3; i<= n; i += 2){
            arr[i/2] = arr[i/2-1] + i*x;
            x++;
            mov += 4*(i/2) + 4*((i-2)*((i-2)/2) + i-2);
        }
        
        //print(arr);
 
        cout << mov << endl;
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
