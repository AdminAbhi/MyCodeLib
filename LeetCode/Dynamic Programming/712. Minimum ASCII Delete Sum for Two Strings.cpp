class Solution {
public:
    int dp[1002][1002];
    
    int go(string &s1,string &s2, int i=0, int j=0)
    {
        if(dp[i][j] != -1) return dp[i][j];
	    
        int cost = 0;
        
	    if(i==s1.length() and j==s2.length()) cost = 0;

	    else if(i==s1.length()) cost += go(s1,s2,i,j+1) + s2[j];
	
	    else if(j==s2.length()) cost += go(s1,s2,i+1,j) + s1[i];
	    
        else if(s1[i] == s2[j]) cost += go(s1,s2,i+1,j+1);
	    
        else cost += min(go(s1,s2,i+1,j) + s1[i], go(s1,s2,i,j+1) + s2[j]);
	
	    return dp[i][j] = cost;
    }
    
    int minimumDeleteSum(string s1, string s2) {
        memset(dp,-1,sizeof(dp));
        
        return go(s1,s2);
    }
};
