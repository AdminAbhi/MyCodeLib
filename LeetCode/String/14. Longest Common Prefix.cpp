class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0) return "";
        
        int l = INT_MAX;
        for(auto &s: strs) l = min(l, (int)s.length());
        
        for(int i=0; i<strs.size(); i++){
            while(l > 0 && strs[i].substr(0,l) != strs[0].substr(0,l)) l--;
        }
        return strs[0].substr(0, l);
    }
};
