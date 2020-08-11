class Solution {
public:
    
    string sortString(string s) {
        vector<int> hash(26);
        int n = s.length();
        for(char c: s) hash[c - 'a']++;
        
        string res;
        while(n){
            for(int i=0; i<26; i++){
                if(hash[i]){
                    res += i+'a';
                    hash[i]--;
                    n--;
                } 
            }
            for(int i=25; i>=0; i--){
                if(hash[i]){
                    res += char(i+'a');
                    hash[i]--;
                    n--;
                } 
            }
        }
        return res;
    }
};
