//@Abhi     FB UserId: abhiavisekkr     Email Id: abhiavisekkr@gmail.com
#include <bits/stdc++.h>
//#include <fstream>
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

bool comp(VI a, VI b){
	return a[2] < b[2];
}
bool comp1(PI a, PI b){
	return a.sec > b.sec;
}

int main() {
	BoostIO;
	
	ifstream fin;
	ofstream fout; 
	fin.open("f_libraries_of_the_world.txt");
	fout.open("f_outfile.txt");
	
	int b, l, d;
	fin >> b >> l >> d;
	
	VI books(b,0);
	for(int i=0; i<b; i++) fin >> books[i];
	
	//VI books(b,0), days(d), stime(l), blim(l);
	VVI libs(l);
	
	vector<VPI> bmat(l);
	VI profit(l,0);
	
	for(int i=0; i<l ;i++){
		libs[i].resize(5);
		libs[i][0] = i;
		fin >> libs[i][1] >> libs[i][2] >> libs[i][3];
		
		bmat[i].resize(libs[i][1]);
		for(int j=0; j<libs[i][1]; j++){
			fin >> bmat[i][j].fst;
			bmat[i][j].sec = books[bmat[i][j].fst];
			profit[i] += bmat[i][j].sec;
		}
		int maxd = libs[i][1] / libs[i][3];
		maxd += libs[i][1] % libs[i][3] == 0? 0: 1;
		 
		libs[i][4] = profit[i] / libs[i][2] + maxd;
		
		sort(bmat[i].begin(), bmat[i].end(), comp1);
	}
	//for(VI i:bmat){ for(int j:i) fout<<j<<" "; fout<<endl;}
	//for(int x=0; x<l; x++){
	//	for(PI i:bmat[x]) 
	//		fout<<i.fst<<","<<i.sec<<" | ";
	//	fout<<endl;
	//}
	
	sort(libs.begin(), libs.end(), comp);
	//print(libs);
	
	int lcnt = 0;
	int n=0, sum=0;
	for(int i=0; i<l; i++){
		if(sum + libs[i][2] <= d){
			n++;
			sum += libs[i][2];
			if(i == l-1){
				for( ; sum < d && lcnt < libs[i][1]; ){
					if(lcnt + libs[i][3] <= libs[i][1]){
						lcnt += libs[i][3];
						sum++;
					}
					else break;
				}
				if(lcnt == 0) n--;
			}
		}
		else break;
	}
	
	fout << n << endl;
	for(int i=0; i<n; i++){
		if(i==n-1 && lcnt > 0){
			fout << libs[i][0] <<" "<< lcnt << endl;
			for(int j=0; j<lcnt; j++){
				fout << bmat[libs[i][0]][j].fst << " ";
			}
			fout << endl;
			continue;
		}
		fout << libs[i][0] <<" "<< libs[i][1] << endl;
		for(int j=0; j< libs[i][1]; j++){
			fout << bmat[libs[i][0]][j].fst << " ";
		}
		fout << endl;
	}
	
	
	fin.close();
	fout.close();
   
	return 0;
}
