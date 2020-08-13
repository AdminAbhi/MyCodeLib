class Solution {
public:
    bool detectCapitalUse(string word) {
        int c = 0, s = 0;
        for(char ch: word){
            if(islower(ch)) s++;
            else c++;
        }
        if(c == 0) return 1;
        else if(s == 0) return 1;
        else if(c == 1 && isupper(word[0])) return 1;
        return 0;
    }
};
