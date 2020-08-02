class Solution {
public:
   
    bool stoneGame(vector<int>& pil) {
        int n = pil.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>> (n));
        
        for(int k=0; k<n; k++){
            for(int i=0, j=k; max(i,j) < n; i++, j++){
                if(i == j) dp[i][j] = {pil[i], 0};
                else{
                    pair<int, int> p1 = {pil[j] + dp[i][j-1].second, dp[i][j-1].first};
                    pair<int, int> p2 = {pil[i] + dp[i+1][j].second, dp[i+1][j].first};
                    
                    if(p1.first > p2.first) dp[i][j] = p1;
                    else dp[i][j] = p2;
                }
            }
        }
        if(dp[0][n-1].first > dp[0][n-1].second) return 1;
        else return 0;
    }
};
