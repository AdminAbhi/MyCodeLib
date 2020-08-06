class Solution {
public:
    int titleToNumber(string s) {
        int col = 0;
        int i = 0;
        while(s.size()){
           col += pow(26, i++) * (s.back() - 'A' + 1);
            s.pop_back();
        }
        return col;
    }
};
