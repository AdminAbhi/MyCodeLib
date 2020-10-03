// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long long l = 1;
        while(l <= n){
            long long m = (l+n)/2;
            if(isBadVersion(m)) n = m-1;
            else l = m+1;
        }
        return l;
    }
};
