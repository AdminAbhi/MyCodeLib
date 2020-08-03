class Solution {
public:
    int subtractProductAndSum(int n) {
        int pro = 1;
        int sum = 0;
        while(n){
            int r = n%10;
            pro *= r;
            sum += r;
            n /= 10;
        }
        return pro - sum;
    }
};
