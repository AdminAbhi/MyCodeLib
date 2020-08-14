class Solution {
public:
    bool checkRecord(string s) {
        int a=0, l=0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'A'){
                if(++a > 1) return 0;  
            } 
            else if(i > 1 && s[i] == 'L' && s[i-1] == 'L' && s[i-2] == 'L') return 0;
        }
        return 1;
    }
};
