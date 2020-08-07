class Solution {
public:
    int xorOperation(int n, int start) {
        int XOR = start;
        for(int i=1; i<n; i++){
            XOR ^= start + (i << 1);
        }
        return XOR;
    }
};
