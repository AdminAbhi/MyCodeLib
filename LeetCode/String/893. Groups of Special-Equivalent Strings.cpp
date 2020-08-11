class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        unordered_set<string> st;
        for(auto &w : A) {
            string odd, even;
            for(int i=0;i<w.size();i+=2) even.push_back(w[i]);
            for(int i=1;i<w.size();i+=2) odd.push_back(w[i]);
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            st.insert(even + odd);
        }
        return st.size();
    }
};
