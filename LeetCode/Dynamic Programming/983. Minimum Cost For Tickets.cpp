class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<bool> ds(days.back()+1, 0);
        vector<int> dp(days.back()+1, 0);
        
        for(int i : days) ds[i] = 1;
        for(int i=1; i<=days.back(); i++){
            if(ds[i] == 0) dp[i] = dp[i-1];
            else{
                int c1 = dp[max(0, i-1)] + costs[0];
                int c2 = dp[max(0, i-7)] + costs[1];
                int c3 = dp[max(0, i-30)] + costs[2];
                dp[i] = min(c1, min(c2, c3));
                
            }
        }
        return dp.back();
    }
};
