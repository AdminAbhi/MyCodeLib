class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        for(auto vs : paths){
            mp[vs[0]]++;
            mp[vs[1]]--;
        }
        for(auto i: mp) if(i.second < 0) return i.first;
        return "lol";
    }
};
