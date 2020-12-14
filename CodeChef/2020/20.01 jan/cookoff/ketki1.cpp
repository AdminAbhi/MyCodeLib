//@Abhi     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
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

bool isPrime(int n) {  
    if (n <= 1) 
        return false; 
    if (n <= 3) 
        return true; 
    if (n % 2 == 0 || n % 3 == 0) 
        return false; 
    for (int i = 5; i * i <= n; i = i + 6) 
        if (n % i == 0 || n % (i + 2) == 0) 
            return false; 
    return true; 
} 

int main() {
	BoostIO;
	int n;  cin>>n;
	VI arr(n);
	
	VI hash(100001,0);
	for (int i=0; i<n; i++){
	  cin>>arr[i];
	  hash[arr[i]]++;
	}
	sort(arr.begin(), arr.end());
	int temp =0;
	for (int i=0; i<n; i++){
	   if(isPrime(arr[i])){
			int cnt = 0;
			for(int j = arr[i]; j < 100001; j *= arr[i]){
				if(hash[j] > 0) cnt++;
			}
			if(cnt == 2){
				cout<<arr[i]<<endl;
				temp = 1;
				break;
			}
		}
	}
	if(temp == 0) cout<<"-1"<<endl;
	return 0;
}
