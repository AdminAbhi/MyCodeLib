class Solution {
public:
    static bool cmp(const string &a, const string &b){
        int ai = 0, bi = 0;
        while(a[ai] != ' ') ai++;
        while(b[bi] != ' ') bi++;
        if(a.substr(ai+1) == b.substr(bi+1)) 
            return a.substr(0, ai) < b.substr(0, bi)? 1: 0;
        return a.substr(ai+1) < b.substr(bi+1)? 1: 0;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> let, dig;
        for(auto s: logs){
            int i = 0;
            while(s[i] != ' ') i++;
            
            if(isdigit(s[i+1])) dig.push_back(s);
            else let.push_back(s);
        }
        sort(let.begin(), let.end(), cmp);
        for(int i=0; i<let.size(); i++) logs[i] = let[i];
        for(int i=0; i<dig.size(); i++) logs[i+let.size()] = dig[i];
        return logs;
    }
};
