class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int res = 0;
        int mc = 0;
        for(int i=0; i<grid.size(); i++){
            int l = grid[i].size();
            mc = max(mc, l);
            int maxx = 0;
            for(int j=0; j<l; j++){
                maxx = max(maxx, grid[i][j]);
                if(grid[i][j]) res += 1;
            }
            res += maxx;
        }
        for(int i=0; i<mc; i++){
            int maxx = 0;
            for(int j=0; j<grid.size(); j++){
                if(i < grid[j].size()) 
                    maxx = max(maxx, grid[j][i]);
            }
            res += maxx;
        }
        return res;
    }
};
