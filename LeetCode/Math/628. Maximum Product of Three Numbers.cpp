class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size()-1;
        int mx = max(nums[r] * nums[r-1] * nums[r-2], nums[l] * nums[l+1] * nums[r]);
        return mx;
    }
};
