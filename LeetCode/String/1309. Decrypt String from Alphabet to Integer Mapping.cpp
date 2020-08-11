class Solution {
public:
    string freqAlphabets(string s) {
        string res;
        for(int i=s.length()-1; i>=0; i--){
            if(s[i] != '#'){
                res += char(s[i] - '0' + 'a' -1);
            }
            else{
                res += char(10*(s[i-2] - '0') + s[i-1] - '0' + 'a' -1);
                i -= 2;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
