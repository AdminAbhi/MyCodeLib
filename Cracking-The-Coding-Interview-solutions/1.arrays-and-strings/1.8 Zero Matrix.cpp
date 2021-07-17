#include<bits/stdc++.h>
using namespace std;

// Time  - O(n*n)
// space - O(1)


void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        vector<int> row(n,1), col(m,1);
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j] == 0){
                    row[i] = 0;
                    col[j] = 0;
                 }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(row[i] == 0 || col[j] == 0) matrix[i][j] = 0;
            }
        }
}

int main(){
	
	int n,m; cin >> n >> m;
	vector<vector<int>> mat(n, vector<int> (m));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cin >> mat[i][j];
	}
	
	rotate(mat);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	
	return 0;
}
