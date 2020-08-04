class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        vector<int> res(num_people);
        int c = 1;
        int idx = 0;
        while(candies){
            res[idx % num_people] += min(c, candies);
            candies -= min(c, candies);
            idx++;
            c++;
        }
        return res;
    }
};
