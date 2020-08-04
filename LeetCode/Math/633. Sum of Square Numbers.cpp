class Solution {
public:
    bool judgeSquareSum(int c) {
        for(long long i=0; i*i <= c; i++){
            int n = sqrt(c - i*i);
            if(n * n == c - i*i) return 1;
        }
        return 0;
    }
};
