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


void solve(VVI &mat, int n, int m){

    map<int, int> mp;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
            mp[mat[i][j]]++;
    }

    VVI arr(2);

    for(auto i: mp){
        int l = i.sec;
        while(l > 0){
            if(l == 1){
                arr[0].PB(i.fst);
                l--;
            }
            else{
                arr[1].PB(i.fst);
                arr[1].PB(i.fst);
                l -= 2;
            }
        }
    }

    int io = 0;
    int odd = arr[0].size();

    if((odd > n) || (odd > 0 && m % 2 == 0)){
        cout << -1 << endl;
        return;
    }
    
    while(odd > 0){
        mat[io][m/2] = arr[0][io];
        odd--;
        io++;
    }
    int i2 = 0;
    if(m % 2 != 0 && io < n){
        while(io < n){
            mat[io++][m/2] = arr[1][i2++];
            mat[io++][m/2] = arr[1][i2++];
        } 
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m/2; j++){
            mat[i][j] = arr[1][i2++];
            mat[i][m-j-1] = arr[1][i2++];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<=m/2; j++){
            if(mat[i][j] != mat[i][m-j-1]){
                cout << -1 << endl;
                return;
            }
        }
    }
    
    print(mat);

}


int main() {
    BoostIO;
    int T;  cin >> T;
    while(T--){
        int n, m; cin >> n >> m;
        VVI mat(n, VI (m));

        for(int i=0; i<n; i++) for(int j=0; j<m; j++) cin >> mat[i][j];

        solve(mat, n, m);
           
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

