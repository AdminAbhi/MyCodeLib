class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for (auto num : nums) {
            sum ^= num;
        }
        vector<int> res{0, 0};
        int lowbit = sum & (-sum);
        for (auto num : nums) {
            if (num & lowbit)
                res[0] ^= num;
            else
                res[1] ^= num;
        }
        return res;
    }
};
