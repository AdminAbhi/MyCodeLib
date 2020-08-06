class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coo) {
        for(int i=2; i<coo.size(); i++){
            if(((coo[i][1] - coo[0][1]) * (coo[1][0] - coo[0][0])) 
                    != ((coo[1][1] - coo[0][1]) * (coo[i][0] - coo[0][0]))) 
                return 0;
        }
        return 1;
    }
};
