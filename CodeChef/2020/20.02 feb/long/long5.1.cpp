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


int dayofweek(int d, int m, int y){  
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };  
    y -= m < 3;  
    return ( y + y / 4 - y / 100 + y / 400 + t[m - 1] + d) % 7;  
}  

bool isleapyear(int  year){  
    if (year % 400 == 0)  
        return true;  
    if (year % 100 == 0)  
        return false;  
    if (year % 4 == 0)  
        return true;  
    return false;  
}  

int main(){
	BoostIO;
	int T;  cin>>T;
	//cout << dayofweek(15,2,2020)<<endl;
	//cout << dayofweek(15,2,2020)<<endl;
	//cout<< dayofweek(16,2,2020) << endl;
	while(T--){
		int sy, ey, sm, em;
		cin >> sm >> sy >> em >> ey;
        
		int count = 0;
		if(sm > 2) sy++;
		if(em < 2) ey--;
		
		while(sy <= ey){
			if(!isleapyear(sy) && (dayofweek(1, 2, sy) == 0))count++;
			if((dayofweek(1, 2, sy) == 6))count++;
			sy++;
		}
		

		cout << count << endl;
	}
	return 0;
}
