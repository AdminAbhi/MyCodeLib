class Solution {
public:
    int minCostToMoveChips(vector<int>& chips) {
        int e = 0, o = 0;
        for(int i: chips){
            if(i%2 == 0) e++;
            else o++;
        }
        return min(e,o);
    }
};
