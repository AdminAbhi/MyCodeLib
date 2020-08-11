class Solution {
public:
    string reverseWords(string s) {
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == ' '){
                reverse(s.begin()+idx, s.begin()+i);
                idx = i+1;
            }
        }
        reverse(s.begin()+idx, s.end());
        return s;
    }
};
