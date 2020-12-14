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


int arr[100001]; int st[400004];

void build(int idx, int s, int e){
    if(s == e){
        st[idx] = arr[s];
        return;
    }
    int mid = (s + e)/2;

    build(2*idx +1, s, mid);
    build(2*idx +2, mid+1, e);

    st[idx] = min(st[2*idx+1], st[2*idx + 2]);
}

int querry(int idx, int s, int e, int qs, int qe){
    if(s > qe || e < qs) return INT_MAX;

    if(s >= qs && e <= qe) return st[idx];

    int mid = (s + e)/2;

    return min(querry(2*idx +1, s, mid, qs, qe), 
				querry(2*idx +2, mid+1, e, qs, qe));
}



int main() {
    BoostIO;

        int n; cin >> n;
        for(int i=0; i<n; i++) cin >> arr[i];
        build(0, 0, n-1);

        int q; cin >> q;
        while(q--){
            int l, r; cin >> l >> r;
            cout << querry(0, 0, n-1, l, r) << endl;
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

