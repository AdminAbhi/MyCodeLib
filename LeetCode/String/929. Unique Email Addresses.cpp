class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for(auto s: emails){
            string r = "";
            for(int i=0; i<s.length(); i++){
                if(s[i] == '@'){
                    r += s.substr(i);
                    break;
                } 
                else if(s[i] == '+'){
                    while(s[i] != '@') i++;
                    r += s.substr(i);
                    break;
                }
                else if(s[i] != '.') r += s[i];
            }
            st.insert(r);
        }
        return st.size();
    }
};
