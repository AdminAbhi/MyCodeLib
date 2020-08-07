class Solution {
public:
    int countPrimeSetBits(int l, int r) {
        set<int> st = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
        int cnt = 0;
        for(int i=l; i<=r; i++){
            if(st.find(__builtin_popcount(i)) != st.end()) cnt++;
        }
        return cnt;
    }
};
