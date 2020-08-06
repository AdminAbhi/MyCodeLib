class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long long n = nums.size();
        long long sum = (n*(n+1))/2;
        for(int i: nums) sum -= i;
        return sum;
    }
};
