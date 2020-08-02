class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int m = A.size();
        int n = A[0].size();
        vector<vector<int>> dp(m, vector<int> (n));
        for(int i=m-1; i>=0; i--){
            for(int j=0; j<n; j++){
                if(i == m-1){
                    dp[i][j] = A[i][j];
                    continue;
                }
                int mini = dp[i+1][j];
                if(j-1 >= 0) mini = min(mini, dp[i+1][j-1]);
                if(j+1 < n) mini = min(mini, dp[i+1][j+1]);
                dp[i][j] = A[i][j] + mini;
            }
        }
        int mini = INT_MAX;
        for(int i=0; i<n; i++) mini = min(mini, dp[0][i]);
        return mini;
    }
};
