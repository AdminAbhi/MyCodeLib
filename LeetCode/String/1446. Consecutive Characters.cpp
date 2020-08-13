class Solution {
public:
    int maxPower(string s) {
        int idx = 0;
        int res = 1;
        for(int i=0; i<s.length(); i++){
            if(s[i] != s[idx]){
                res = max(res, i - idx);
                idx = i;
            }
        }
        return max(res, (int)s.length() - idx);
    }
};
