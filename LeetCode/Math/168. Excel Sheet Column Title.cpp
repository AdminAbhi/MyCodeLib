class Solution {
public:
    string convertToTitle(int n) {
        string col = "";
        while(n){
            int r = n % 26;
            if(r == 0){
                col += "Z";
                n = (n-1) / 26;
            } 
            else{
                col += (char)('A' + r -1);  
                n = n / 26;
            } 
        }
        reverse(col.begin(), col.end());
        return col;
    }
};
