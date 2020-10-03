class Solution {
public:
    int arrangeCoins(int n) {
        long left = 0, right = n;
        long k, curr;
        while (left <= right) {
            k = left + (right - left) / 2;
            curr = k * (k + 1) / 2;
            if (curr == n){
                return (int)k;  
            } 
            if (n < curr) {
                right = k - 1;
            } 
            else {
                left = k + 1;
            }
        }
        return (int)right;
    
        // long long d = (int)sqrt(1+(8*(long long)n));
        // long long n1 = (d-1)/2;  
        // return (int)n1;
    }
};
