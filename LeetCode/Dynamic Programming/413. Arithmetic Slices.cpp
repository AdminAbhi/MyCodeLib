class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
        int res = 0;
        int idx = 0;
        while(idx < n-2){
            int diff = A[idx+1] - A[idx];
            int i = idx;
            while(i < n-1 && A[i+1] - A[i] == diff){
                i++;
            }
            int l = i - idx + 1;
            if(l >= 3){
                res += (l*(l+1))/2 - l - l +1;
            }
            idx = i;
        }
        return res;
    }
};
