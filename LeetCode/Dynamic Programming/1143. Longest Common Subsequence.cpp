class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int l1 = s1.length();
        int l2 = s2.length();
        
        int dp[l1+1][l2+1];
        memset(dp, 0, sizeof(dp));
        
        for(int i=1; i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];  
                } 
                else{
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);  
                } 
            }
        }
        return dp[l1][l2];
    }
};
