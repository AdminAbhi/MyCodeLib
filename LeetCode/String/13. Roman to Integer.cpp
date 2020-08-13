class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'M', 1000}, {'D', 500}, {'C', 100}, {'L', 50}, {'X', 10}, {'V', 5}, {'I', 1}};
        int res = 0;
        for(int i=0; i<s.length()-1; i++){
            if(s[i] == 'I' && s[i+1] == 'V') res -= mp[s[i]];
            else if(s[i] == 'I' && s[i+1] == 'X') res -= mp[s[i]];
            
            else if(s[i] == 'X' && s[i+1] == 'L') res -= mp[s[i]];
            else if(s[i] == 'X' && s[i+1] == 'C') res -= mp[s[i]];
            
            else if(s[i] == 'C' && s[i+1] == 'D') res -= mp[s[i]];
            else if(s[i] == 'C' && s[i+1] == 'M') res -= mp[s[i]];
            
            else res += mp[s[i]];
        }
        return res + mp[s.back()];
    } 
};
