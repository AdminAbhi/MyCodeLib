//=============================================================================
// @abhi_admin    FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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
inline void print(map<int,int> m){for(auto i:m) print(i); cout<<endl;}

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



bool is_ok(LL n){
    string s = to_string(n);
    for(int i=0; i<s.length(); i++){
        if((i+1) % 2 != (s[i] - '0') % 2) return 0;
    }
    return 1;
}


LL till_this(LL n){
    LL res = 0;
    string s = to_string(n);

    for(int i=0; i<s.length(); i++){
        if(i & 1){
            if((s[i] - '0') & 1)
                res += (((s[i] - '0') / 2) + 1) * pow(5, s.length()- i - 1);
            else
                res += ((s[i] - '0') / 2) * pow(5, s.length()- i - 1);
        }
        else{
            res += ((s[i] - '0') / 2 ) * pow(5, s.length()- i - 1);
        }

        if(i < s.length()-1){
            if((s[i] - '0') % 2 != i % 2){
                res += ((s[i+1] - '0') / 2) * pow(5, s.length() - i - 2);
            }

        }
    }
    return res + is_ok(n);
}




int main() {
	BoostIO;
	int T = 1;
	cin >> T;
	int t = 1;
	while(t <= T){

		cout << "Case #" << t++ << ": ";

        LL l, r; cin >> l >> r;

        VLL tot(20);
        for(LL i=1; i<19; i++){
            tot[i] = 9 * pow(10, i-1);
        }
        //print(tot);

        int dl = to_string(l).length();
        int dr = to_string(r).length();

        LL lim = 1;
        for(int i=0; i<dl; i++) lim *= 10;
        lim--;

        LL cnt = till_this(lim) - till_this(l) + is_ok(l);

        //cout << cnt << endl;

        for(int i = dl + 1; i < dr; i++){
            cnt += pow(5, i);
        }
        //cout << cnt << " ";

        cout << till_this(r) << ", " << till_this(l) << " " << is_ok(l) << endl;

        if(dl == dr) cnt = till_this(r) - till_this(l) + is_ok(l);
        else{
            cnt += till_this(r);
        }

        cout << cnt << endl;
    }
	return 0;
}

//=============================================================================
//-----------------------------ADMIN-ABHI-SHAKE--------------------------------
//=============================================================================

