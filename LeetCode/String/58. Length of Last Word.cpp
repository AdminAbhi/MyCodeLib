class Solution {
public:
    int lengthOfLastWord(string s) {
        int l = 0;
        int i=s.length()-1;
        while(i >= 0 && s[i] == ' ') i--;
        for( ; i>=0; i--){
            if(s[i] == ' ') break;
            l++;
        }
        return l;
    }
};
