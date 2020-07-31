class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ma = 0;
        int mi = INT_MAX;
        for(uint i=0; i<p.size(); i++){
            if(p[i] < mi){
                mi = p[i];
            }    
            else{
                ma = max(ma, p[i] - mi);   
            }
        }
        return ma;
    }
};