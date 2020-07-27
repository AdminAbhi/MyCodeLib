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

string getStr(vector<string> str, int n){
		unsigned int maxlen = 0;
		int idx;

		for(int i=0; i<n;i++){
			//cin >> str[i];
			reverse(str[i].begin(), str[i].end());
			if(str[i].length() > maxlen){
				maxlen = str[i].length();
				idx = i;
			}
				
		}

		//for(string ss : str) cout << ss << endl;
		
		string s = "";
		//int idx = 0;

		for(unsigned int j=0; j<maxlen-1; j++){
			char c = str[idx][j];
			bool flag = true;

			for(int i=0; i<n; i++){
				if(str[i].length() == 1) continue;
				if(str[i].length()-2 < j) continue; 

				//cout << i << endl;
 				
				if(str[i][j] != c){
					s = "*";
					flag = false;
					break;
				}
			}
			if(!flag) break;
			s.push_back(c);
		}
		reverse(s.begin(), s.end());
	return s;
}

int main() {
	BoostIO;
	int T;  cin >> T;
	int t = 1;
	while(t <= T){
		int n; cin >> n;
		
		vector<string> str(n);

		bool type = true;
		 
		for(int i=0; i<n;i++){
			cin >> str[i];
			if(str[i][0] != '*') type = false;
		} 

		if(type){
			string s = getStr(str, n);
		
			cout << "Case #" << t << ": " << s << endl;
		}

		else{
			vector<string> v1(n), v2(n);
			
			for(int i=0; i<n; i++){

				unsigned int idx = 0;

				while(str[i][idx] != '*') v1[i].PB(str[i][idx++]);

				v1[i].PB('*');

				reverse(v1[i].begin(), v1[i].end());

				//v2[i].PB('*');
				
				while(idx < str[i].length()) v2[i].PB(str[i][idx++]); 
			}

			//for(int i=0; i<n; i++) cout << v1[i] << " -- " << v2[i] << endl;
			
			string s1 = getStr(v1, n);
			string s2 = getStr(v2, n);

			//cout << s1 << " " << s2 << endl;

			reverse(s1.begin(), s1.end());
			string s = s1 + s2;

			if(s1 == "*" || s2 == "*") cout << "Case #" << t << ": " << '*' << endl;
			else cout << "Case #" << t << ": " << s << endl;
		}
		t++;
    }
	return 0;
}
