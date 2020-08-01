class Solution {
public:
    int countSquares(vector<vector<int>> mat) {
        int m = mat.size();
        int n = mat[0].size();
        
        int cnt = 0;
        
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(i == 0 || j == 0){ 
                    if(mat[i][j] == 1) cnt++;
                }
                else if(mat[i][j] == 1){
                    mat[i][j] = 1 + min(mat[i-1][j-1], min(mat[i-1][j], mat[i][j-1]));
                    cnt += mat[i][j];
                }
            }
        }
        
        return cnt;
    }
};
