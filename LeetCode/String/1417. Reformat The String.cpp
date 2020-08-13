class Solution {
public:
    string reformat(string s) {
        string d, a;
        for(char c: s){
            if(isdigit(c)) d += c;
            else a += c;
        }
        if(abs((int)a.length() - (int)d.length()) > 1) return "";
       
        if(d.length() > a.length()) swap(a, d);
        for(int i=0; i<s.length(); i++){
            if(i%2==0) s[i] = a[i/2];
            else s[i] = d[i/2];
        }
        return s;
    }
};
