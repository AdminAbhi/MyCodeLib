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

bool cmp(VI a, VI b){
	return a[1] < b[1]; 
}

int main() {
	BoostIO;
	int T;  cin>>T;
	int t=1;
	while(t <= T){
		int n; cin >> n;
		VVI job(n);
		for(int i=0; i<n; i++){
			job[i].resize(3);
			cin >> job[i][0] >> job[i][1];
			job[i][2] = i;
		}
		sort(job.begin(), job.end(), cmp);
		
		VVI cja(2);
		cja[0].resize(2);
		cja[1].resize(2);
		bool curr = 0;
		
		vector<char> str(n);
		//for(int i=0; i<n; i++) str += "_";
		
		bool flag = false;
		
		for(int i=0;i<n; i++){
			if(job[i][0] >= cja[curr][1]){
				if(curr == 0) str[job[i][2]] = 'C';	
				else str[job[i][2]] = 'J';
			}
			else if(job[i][0] >= cja[1 - curr][1]){
				curr = 1 - curr;
				if(curr == 0) str[job[i][2]] = 'C';	
				else str[job[i][2]] = 'J';
			}
			else{
				flag = true;
				break;
			} 
			cja[curr][0] = job[i][0];
			cja[curr][1] = job[i][1];
		}
		string res = "";
		for(int i=0; i<n; i++) res += str[i];
		
		if(flag) cout << "Case #" << t << ": " << "IMPOSSIBLE" << endl;
		else cout << "Case #" << t << ": " << res << endl;
		
	
		t++;
   }
	return 0;
}
