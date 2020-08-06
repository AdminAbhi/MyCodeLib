class Solution {
public:
    int countOdds(int low, int high) {
        int n = high - low + 1;
        return low % 2 == 0? n/2: (n+1)/2;
    }
};
