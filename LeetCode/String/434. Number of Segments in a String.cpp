class Solution {
public:
    int countSegments(string s) {
        istringstream input(s);
        int cnt = 0;
        string ss;
        while(input >> ss) cnt++;
        return cnt;
    }
};
