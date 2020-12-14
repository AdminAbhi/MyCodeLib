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


bool isSqr(int &n){
    int x = sqrt(n);
    if(x*x == n) return 1;
    return 0;
}


int main() {
    BoostIO;
    int T;  cin >> T;
    int t = 1;
    while(T--){
        LL n, q; cin >> n >> q;

        VLL arr(n);
        VLL a(n+1, 0);
        LL res = 0;
        
        for(LL i=0; i<n; i++){
            cin >> arr[i];
            a[i+1] = a[i] + arr[i];
        } 
        //print(arr);
        
        while(q--){
            char c;
            int x , y;
            cin >> c >> x >> y;

            if(c == 'Q'){
                LL sw = 0;
                for(LL i=0; i<= y-x; i++){
                    if(i%2 == 0)
                        sw += arr[x+i-1] * (i+1);
                    else
                        sw -= arr[x+i-1] * (i+1);
                }
                //cout << sw << " => ";
                res += sw; 
            }
            else{
                arr[x-1] = y;
            }
            //print(arr);
        }
        
        cout << "Case #" << t << ": " << res << endl;
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

