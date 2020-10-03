class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> a1(nums1.begin(), nums1.end()), a2(nums2.begin(), nums2.end());
        vector<int> res;
        for(int i: a1){
            if(a2.find(i) != a2.end()) res.push_back(i);
        }
        return res;
    }
};
