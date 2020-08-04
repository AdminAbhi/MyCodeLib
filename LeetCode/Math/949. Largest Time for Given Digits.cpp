class Solution {
public:
    string largestTimeFromDigits(vector<int>& A) {
        int ans = -1;
        for (int i = 0; i < 4; ++i)
            for (int j = 0; j < 4; ++j) if (j != i)
                for (int k = 0; k < 4; ++k) if (k != i && k != j) {
                    int l = 6 - i - j - k;
                    int hours = 10 * A[i] + A[j];
                    int mins = 10 * A[k] + A[l];
                    if (hours < 24 && mins < 60)
                        ans = max(ans, hours * 60 + mins);
                }
        string s(5, ':');
        s[0] = (ans/60)/10 + '0';
        s[1] = (ans/60)%10 + '0';
        s[3] = (ans%60)/10 + '0';
        s[4] = (ans%60)%10 + '0';
        return ans >= 0 ? s : "";
    }
};
