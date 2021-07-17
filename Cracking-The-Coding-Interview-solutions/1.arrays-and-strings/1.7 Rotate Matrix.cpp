#include<bits/stdc++.h>
using namespace std;

// Time  - O(n*n)
// space - O(1)

void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for(int i=0; i<n; i++){
            reverse(matrix[i].begin(), matrix[i].end());
        }
        
    }

int main(){
	int n; cin >> n;
	vector<vector<int>> mat(n, vector<int> (n));
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cin >> mat[i][j];
	}
	
	rotate(mat);
	
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++) cout << mat[i][j] << " ";
		cout << endl;
	}
	
	
	return 0;
}
