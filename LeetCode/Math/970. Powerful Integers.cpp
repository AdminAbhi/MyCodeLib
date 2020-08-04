class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> st;
        for(long long i=1; i<bound; i*=x){
            for(long long j=1; i+j<=bound; j*=y){
                st.insert(i+j);
                if(y == 1) break;
            }
            if(x == 1) break;
        }
        vector<int> res;
        for(auto i: st) res.push_back(i);
        return res;
    }
};
