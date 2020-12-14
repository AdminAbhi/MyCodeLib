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
#define PB push_back
#define MP make_pair
#define fst first
#define sec second
#define MOD7 1000000007
#define BoostIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

inline void print(VI v){ for(int i:v) cout<<i<<" "; cout<<endl; }
inline void print(VLL v){ for(LL i:v) cout<<i<<" "; cout<<endl; }
inline void print(VVI v){ for(VI i:v){ for(int j:i) cout<<j<<" "; cout<<endl;}}
inline void print(VPI P){for(PI i:P) cout<<i.fst<<","<<i.sec<<" | ";cout<<endl;}

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

LL findSubarraySum(VLL arr, LL n) { 

    unordered_map<LL, LL> ps; 
    LL res = 0; 
    LL cs = 0; 
  
    for (int i = 0; i < n; i++) { 
		cs += arr[i]; 
  
        if (cs == 1) res++;         
  
        if (ps.find(cs - 1) !=  ps.end())  
            res += (ps[cs - 1]); 
 
        ps[cs]++; 
    } 
    return res; 
} 

int count2(LL n){
	if(n % 4 == 0) return 2;
	if(n % 2 == 0) return 1;
	return 0;
}

int main() {
	BoostIO;
	int T;  cin >> T;
	while(T--){
		LL n; cin >> n;
		VLL arr(n);

		for(int i=0; i<n; i++){
			cin >> arr[i];
			arr[i] = count2(abs(arr[i]));
		}
		LL res;
		
		if(n%2 == 0) res = (n/2)*(n+1);
		else res = n*((n+1)/2);

		//print(arr);

		LL s = findSubarraySum(arr, n);

		
		cout << res - s << endl;
		
   }
	return 0;
}
