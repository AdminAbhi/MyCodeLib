class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i: nums) mp[i]++;
        int res = 0;
        for(auto i: mp) res += (i.second * (i.second-1))/2;
        return res;
    } 
};
