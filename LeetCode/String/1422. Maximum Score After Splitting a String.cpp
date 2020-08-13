class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int one = 0, zero = 0, res = 0;
        
        for(char c: s) if(c == '1') one++;
        
        for(int i=0; i<n-1; i++){
            if(s[i] == '0'){
                res = max(res, ++zero + one);
            }
            else{
                res = max(res, --one + zero);
            }
        }
        return res;
    }
};
