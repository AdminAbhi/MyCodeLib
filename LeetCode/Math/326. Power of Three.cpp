class Solution {
public:
    bool isPowerOfThree(int n) {
        // 3^19 = 1162261467
         return n > 0 && 1162261467 % n == 0;
    }
};
