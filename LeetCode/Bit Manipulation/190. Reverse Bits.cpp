class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32> str(n);
        string s = str.to_string();
        reverse(s.begin(), s.end());
        return stoll(s, 0, 2);
    }
};
