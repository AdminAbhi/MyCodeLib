class Solution {
public:
    bool isPowerOfTwo(int n) {
        uint x = INT_MAX; // INT_MAX = 2^31-1;
        return n > 0 && (x+1) % n == 0;
    }
};
