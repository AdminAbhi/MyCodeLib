#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m; 
	cin >> n >> m;
	vector<set<pair<int, int>>> rset(n+1), cset(m+1);
	vector<vector<int>> mat(n, vector<int> (m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin >> mat[i][j];
		}
	}
	
	int rc = 0, cc = 0;
	int s = -1, e = -1;
	
	for(int i=0; i<n; i++){	
		for(int j=0; j<m; j++){
			if(mat[i][j] == 6){
				e = j;
				if(s == -1) s = j;
				if(j == m-1){
					if(rset[i].find({s, e}) == rset[i].end()) rc++;
					rset[i+1].insert({s, e});
				}
			}
			else if(s != -1){
				if(rset[i].find({s, e}) == rset[i].end()) rc++;	
				rset[i+1].insert({s, e});
				s = e = -1;
			}
			else s = e = -1;
		}
		s = e = -1;
	}
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(mat[j][i] == 6){
				e = j;
				if(s == -1) s = j;
				if(j == n-1){
					if(cset[i].find({s, e}) == cset[i].end()) cc++;
					cset[i+1].insert({s, e});
				}
			}
			else if(s != -1){
				if(cset[i].find({s, e}) == cset[i].end()) cc++;
				cset[i+1].insert({s, e});
				s = e = -1;
			}
			else s = e = -1;
		}
		s = e = -1;
	}
	cout << min(rc, cc);
	return 0;
}
