class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length() == 0) return 0;
        int l=0, r=s.length()-1;
        while(l < r) if(s[l++] != s[r--]) return 2;
        return 1;
    }
};
