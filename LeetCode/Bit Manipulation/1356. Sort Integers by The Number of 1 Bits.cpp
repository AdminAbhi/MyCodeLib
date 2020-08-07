bool cmp(int &a, int &b){
    int a1 = __builtin_popcount(a);
    int b1 = __builtin_popcount(b);
    if(a1 < b1) return 1;
    else if(a1 > b1) return 0;
    return a < b;
}

class Solution {
public:
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
};
