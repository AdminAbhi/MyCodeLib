class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,0));
        for(int i=1; i<=m; i++){
            for(int j=1; j<=n; j++){
                dp[i][j] = dp[i][j-1] + mat[i-1][j-1];
            }
        }
        for(int j=1; j<=n; j++){
            for(int i=1; i<=m; i++){
                dp[i][j] += dp[i-1][j];
            }
        }
        //return dp;
        vector<vector<int>> res(m, vector<int> (n));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                res[i][j] = dp[min(m, i+k+1)][min(n, j+k+1)]
                            - dp[max(i-k, 0)][min(n, j+k+1)]
                            - dp[min(i+k+1, m)][max(j-k, 0)]
                            + dp[max(i-k, 0)][max(j-k, 0)];
            }
        }
        return res;
    }
};
