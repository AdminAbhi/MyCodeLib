class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int l = 0, r = A.size()-1;
        while(l < r){
            int mid = (l + r)/2;
            if(A[mid-1] < A[mid] && A[mid] > A[mid+1]) return mid;
            else if(A[mid-1] < A[mid]) l = mid;
            else r = mid;
        }
        return -1;
    }
};
