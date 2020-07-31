
class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int n = nums.size();
        arr.resize(n+1);
        for(int i=0; i < n; i++) arr[i+1] = arr[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return arr[j+1] - arr[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
