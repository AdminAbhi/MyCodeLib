class Solution {
public:
    int f(string s){
        vector<int> hash(26, 0);
        for(char c: s) hash[c-'a']++;
        for(int i=0; i<26; i++) if(hash[i]) return hash[i];
        return 0;
    }
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> fr(12, 0);
        vector<int> res;
        for(auto w: words){
            int x = f(w);
            fr[x]++;
        }
        for(int i = 9; i >= 0; i--){
            fr[i] += fr[i+1];
        }
        for(auto q: queries){
            int x = f(q);
            res.push_back(fr[x+1]);
        }
        return res;
    }
};
