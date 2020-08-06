class Solution {
public:
    string addBinary(string a, string b) {
        if(a.length() < b.length()) swap(a, b);
        
        int l1 = a.length();
        int l2 = b.length();
        
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        
        string res = "";
        int c = 0;
        
        for(int i=0, j=0; i < l1; i++, j++){
            int r = a[i] - '0' + (j < l2? b[j] - '0': 0) + c;
            c = r/2;
            res += (char)('0' + r%2);
        }
        if(c) res += '1';

        reverse(res.begin(), res.end());
        return res;
    }
};
