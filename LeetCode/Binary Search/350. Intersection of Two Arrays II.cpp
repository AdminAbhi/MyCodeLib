class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, pair<int,int>> mp;
        for(int i: nums1) mp[i].first++;
        for(int i: nums2) mp[i].second++;
        vector<int> res;
        for(auto i: mp){
            for(int j=0; j<min(i.second.first, i.second.second); j++) 
                res.push_back(i.first);
        }
        return res;
    }
};
