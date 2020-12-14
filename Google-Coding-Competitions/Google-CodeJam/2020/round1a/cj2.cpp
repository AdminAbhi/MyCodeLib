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

// ifstream fin; ofstream fout; fin.open("input.txt"); fout.open("output.txt");
// fin >> x; fout << x; fin.close(); fout.close();

int main() {
	BoostIO;
	int T;  cin >> T;
	int t = 1;
	
	while(t <= T){
		int n; cin >> n;
	 


	   
	    cout << "Case #" << t << ":" << endl;

		LL sum = 0;
		int i = 1;

		if(n < 501)
	    while(sum < n){
			cout << i << " " << 1 << endl;
			sum++;
			i++;
		}
		else if(n == 501){
			while(sum < n){
				if(i==3){
					cout << 3 << " " << 2 << endl;
					sum += 2;
				}
				cout << i << " " << 1 << endl;
				sum++;
				i++;
			}
		}
		else{
			cout << 1 << " " << 1 << endl;
			sum++;
			i++;
			int res = n - sum;
			while(res >= i-1 && sum < n){
				sum += i-1;
				res = n - sum;
				cout << i << " " << i-1 << endl;
				i++;
			}
			i--;
			while(sum < n){
				
				cout << i << " " << i << endl;
				sum++;
				i++;
			}
		}
		 t++;
    }
	return 0;
}
