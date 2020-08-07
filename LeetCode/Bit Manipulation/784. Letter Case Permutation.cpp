class Solution {
public:
    void all(string &s, int l, int n, vector<string> &vs){
        if(l == n){
            vs.push_back(s);
        }
        else if(!isalpha(s[l])){
            all(s, l+1, n, vs);
        }
        else{
            s[l] = tolower(s[l]);
            all(s, l+1, n, vs);
            
            s[l] = toupper(s[l]);
            all(s, l+1, n, vs);
        }
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> vs;
        all(S, 0, S.length(), vs);
        return vs;
    }
};
