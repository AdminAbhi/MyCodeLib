class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> hash(26);
        for(char c: text) hash[c-'a']++;
        int m = INT_MAX;
        m = min(m, hash['b' - 'a']);
        m = min(m, hash['a' - 'a']);
        m = min(m, hash['l' - 'a']/2);
        m = min(m, hash['o' - 'a']/2);
        m = min(m, hash['n' - 'a']);
        return m;
    }
};
