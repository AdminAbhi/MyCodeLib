class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int till = nums[0];
        int maxi = till;
        for(int i=1; i<n; i++){
            till = max(till + nums[i], nums[i]);
            maxi = max(maxi, till);
        }
        return maxi;
    }
};
