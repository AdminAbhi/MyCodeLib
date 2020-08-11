class Solution {
public:
    int balancedStringSplit(string s) {
        int cnt = 0, res = 0;
        for(char c : s){
            if(c == 'L') cnt++;
            else cnt--;
            res += cnt == 0;
        }
        return res;
    }
};
