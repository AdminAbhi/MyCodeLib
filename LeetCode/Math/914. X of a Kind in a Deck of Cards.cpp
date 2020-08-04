class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> mp;
        for(int i: deck){
            mp[i]++;  
        } 
        int mi = mp[deck.back()];
        for(auto i: mp){
            mi = __gcd(mi, i.second);  
        } 
        if(mi < 2) return 0;
        for(auto i: mp){
            if(i.second % mi != 0) return 0;
        }
        return 1;
    }
};
