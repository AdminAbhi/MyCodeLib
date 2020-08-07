class Solution {
public:
    int numberOfSteps (int num) {
        int step = 0;
        while(num){
            if(num & 1) num-=1;
            else num >>= 1;
            step++;
        }
        return step;
    }
};
