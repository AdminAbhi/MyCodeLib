class Solution {
public:
    vector<string> split(string s, char c){
        vector<string> res;
        int idx = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == c){
                res.push_back(s.substr(idx, i-idx));
                idx = i+1;
            }
        }
        res.push_back(s.substr(idx));
        return res;
    }
    string toGoatLatin(string S) {
        vector<string> s = split(S, ' ');
        string res = "";
        string a = "a";
        for(int i=0; i<s.size(); i++){
            char c = tolower(s[i][0]);
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'){
                s[i] = s[i] + "ma" + a;
            }
            else{
                s[i] = s[i].substr(1) + s[i][0] + "ma" + a;
            }
            a += 'a';
            res += s[i] + " ";
        }
        res.pop_back();
        return res;
    }
};
