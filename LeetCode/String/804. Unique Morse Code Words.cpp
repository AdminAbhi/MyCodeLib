class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> res;
        vector<string> v = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        for(auto w: words){
            string s;
            for(char c: w){
                s += v[c-'a'];
            }
            res.insert(s);
        }
        return res.size();
    }
};
