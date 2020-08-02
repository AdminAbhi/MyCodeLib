class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> pre(n, vector<int> (m, 0));
        for(int i=0; i<n; i++){
            int cnt = 0;
            for(int j = m-1; j>=0; j--){
                if(mat[i][j] == 1){
                    cnt += 1;
                    pre[i][j] = cnt;
                }
                else{
                    cnt = 0;
                }
            }
        }
        int tot = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int x = INT_MAX;
                for(int k = i; k<n; k++){
                    if(mat[k][j] == 0) break;
                    x = min(x, pre[k][j]);
                    tot += x;
                }
            }
        }
        return tot;
    }
};
