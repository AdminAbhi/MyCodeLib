class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int A = 0, B = 0, n = seq.length();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                if (A < B) ++A;
                else ++B, res[i] = 1;
            } else {
                if (A > B) --A;
                else --B, res[i] = 1;
            }
        }
        return res;
    }
};
