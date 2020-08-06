class Solution {
public:
    int addDigits(int n) {
        while(to_string(n).length() > 1){
            int sum = 0;
            while(n){
                sum += n%10;
                n /= 10;
            }
            n = sum;
        }
        return n;
    }
};
