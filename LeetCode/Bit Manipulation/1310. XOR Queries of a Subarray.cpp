class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int l = arr.size();
        vector<int> hash(l+1);
        for(int i=1; i<=l; i++){
            hash[i] = hash[i-1]^arr[i-1];
        }
        vector<int> res;
        for(auto i: queries){
            res.push_back(hash[i[1]+1] ^ hash[i[0]]);
        }
        return res;
    }
};
