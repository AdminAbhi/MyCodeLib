class Solution {
public:
    int isPrefixOfWord(string s, string sw) {
        int n = s.length();
        int l = sw.length();
        if(n >= l) if(sw == s.substr(0, l)) return 1;
        int cnt = 1;
        for(int i=0; i<n; i++){
            if(s[i] == ' ') cnt++;
            if(s[i] == ' ' && sw == s.substr(i+1, l)) return cnt;
        }
        return -1;
    }
};
