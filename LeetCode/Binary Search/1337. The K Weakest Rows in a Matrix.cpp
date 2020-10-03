class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> vp;
        for(int i=0; i<mat.size(); i++){
            int l = 0, r = mat[i].size()-1;
            while(l <= r){
                int m = (l+r)/2;
                if(mat[i][m] == 1) l = m+1;
                else r = m-1;  
            }
            vp.push_back({l, i});
        }
        sort(vp.begin(), vp.end());
        vector<int> res;
        for(int i=0; i<k; i++) res.push_back(vp[i].second);
        return res;
    }
};
