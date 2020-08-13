class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        vector<int> hash(26);
        for(char c: magazine) hash[c-'a']++;
        for(char c: ransomNote){
            if(--hash[c-'a'] < 0) return 0;
        } 
        return 1;
    }   
};
