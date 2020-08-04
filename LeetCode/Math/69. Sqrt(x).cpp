class Solution {
public:
    int mySqrt(int x) {
        long long lo = 0;
        long long hi = x;
        int ans = 0;
        while(lo <= hi){
            long long mid  = lo + (hi-lo)/2;
            long long sq = mid * mid;
            if(sq == x) return mid;
            else if(sq > x) hi = mid-1;
            else{
                ans = mid;
                lo = mid+1;
            }
        }
        return ans;
    }
    
};
