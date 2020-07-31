class Solution {
public:
    
    int rob(vector<int>& nums, int i, int n, int sum, unordered_map<int, int> &mp){
        if(i == n){
            return 0;
        }
        else if(i == n-1){
            return nums[i];
        }
        if(mp.find(i) != mp.end()) return mp[i];
        
        int curr = nums[i] + rob(nums, i+2, n, sum+nums[i], mp);
        int next = rob(nums, i+1, n, sum, mp);
        
        mp[i] = max(curr, next);
        
        return mp[i];
    }
    
    int rob(vector<int>& nums) {
        int sum = 0;
        unordered_map<int, int> mp;
        return rob(nums, 0, nums.size(), sum, mp);
    }
};
