class Solution {
public:
    int numSplits(string s) {
        int l = s.length();
        int cnt = 0;
        
        unordered_set<char> s1, s2;
        vector<int> right(l);
        
        for(int i=l-1; i>=0; i--){
            s1.insert(s[i]);
            right[i] = s1.size();
        }
        for(int i=0; i<l-1; i++){
            s2.insert(s[i]);
            if(s2.size() == right[i+1]) cnt++;
        }
        return cnt;
    }
};
