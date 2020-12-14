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

        VI arr(n);
        int last;
        for(int i=0; i<n; i++){
            cin >> arr[i];
            if(arr[i] == 1) last = i;
        } 

        LL step = 0;
        
        int ii = 0;
        while(ii < n && arr[ii] != 1) ii++;

        int ni = ii+1;

        while(ni < n && arr[ni] != 1) ni++;

        if(n - last + ni < )

        
        int pre = 0;
        while(pre < n && arr[pre] != 1) pre++;

        
        
        for(int i=pre+1; i<n; ){
            bool foo = 1;
            while(i < n && arr[i] != 1){
                i++;
                foo = 0;
            }
            if(i >= n) break;
            
            int next = i+1;
            while(next < n && arr[next] != 1) next++;

            if(next < n && (next - pre < i - pre + next - pre)){
                step += next - pre;
                arr[i] += arr[pre] + arr[next];
                arr[pre] = 0;
                arr[next] = 0;
                pre = next + 1;
            }
            else {
                step += i - pre;
                arr[pre] += arr[i];
                arr[i] = 0;
                pre = i+1;
            }
            

            while(pre < n && arr[pre] != 1) pre++; 

            i = pre + 1;
             
        }
        //print(arr);
        
        for(int i=0; i<n; i++){
            if(arr[i] == 1){
                step = -1;
                break;
            } 
        }
        
        cout << step << endl;
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

