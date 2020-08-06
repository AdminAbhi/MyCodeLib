class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(n+1);
        int rep;
        for(int i=0; i<n; i++){
            hash[nums[i]]++;
            if(hash[nums[i]] == 2) rep = nums[i];
        }
        for(int i=1; i<=n; i++) if(hash[i] == 0) return {rep, i};
        return {0,0};
    }
};
