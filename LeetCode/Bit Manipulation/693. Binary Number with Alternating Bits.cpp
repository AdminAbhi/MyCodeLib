class Solution {
public:
    bool hasAlternatingBits(int n) {
        bool last = (n & 1) > 0? 1: 0;
        n >>= 1;
        while(n){
            if(last){
                if((n & 1) > 0) return 0;
            }
            else{
                if((n & 1) == 0) return 0;
            }
            last = 1- last;
            n >>= 1;
        }
        return 1;
    }
};
