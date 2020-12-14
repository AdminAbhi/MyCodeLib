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
        int n; cin >> n;
        string s1, s2; cin >> s1 >> s2;

        if(s1 == s2){
            cout << 0 << endl;
            continue;
        }
        
        VI a(n, 0);
        for(int i=0; i<n; i++){
            if(s1[i] != s2[i]) a[i] = 1;
        }
        VVI res;
        
        for(int i=0; i<n; ){
            VI b;
            bool check = 1;
            while(i < n && a[i] != 1){
                i++;
                check = 0;
            }

            if(i >= n) break;
            
            char c = s2[i];
            int got;
            //bool foo = 1;

            for(int j=0; j<n; j++){
                if(s1[j] == c){
                    b.PB(j);
                    got = j;
                    break;
                }
            }

            if(b.size() == 0){
                s1 = "_";
                break;
            }
            
            for(int j = i; j<n; j++){
                if(j == got) continue;
                if(a[j] == 1 && s2[j] == c && s1[j] >= c){
                    b.PB(j);
                }
            }

            if(b.size() > 1){
                res.PB(b);
                for(int j: b){
                    s1[j] = c;
                    a[j] = 0;
                }
            }
            
            if(check) i++;
            
        }

        if(s1 == s2){
            cout << res.size() << endl;
            for(unsigned int i=0; i<res.size(); i++){
                cout << res[i].size() << " ";
                print(res[i]);
            }
        }
        else cout << "-1" << endl;
           
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

