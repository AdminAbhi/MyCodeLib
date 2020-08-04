class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int ma = INT_MIN;
        int mi = INT_MAX;
        for(int i=0; i<A.size(); i++){
            ma = max(ma, A[i]);
            mi = min(mi, A[i]);
        }
        int mid = (ma + mi)/2;
        ma = max(mid, ma-K);
        mi = min(mid, mi+K);
        return ma - mi;
    }
};
