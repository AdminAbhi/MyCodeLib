class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num == 1) return 1;
        long long l = 0;
        long long r = num;
        while(l < r){
            long long mid = (l+r)/2;
            long long sq = mid * mid;
            if(sq == num) return 1;
            else if(sq > num) r = mid;
            else l = mid+1;
        } 
        return 0;
    }
};
