class Solution {
public:
    string makeGood(string s) {
        int l = s.length();
        string res = "";
       
        for(int i=0; i<l; i++){
            if(res.length() == 0){
                res += s[i];  
            } 
            else if(abs(res.back() - s[i]) == 32){
                res.pop_back();
            }
            else res += s[i];
        }
        return res;
    }
};
