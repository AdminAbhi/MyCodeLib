class Solution {
public:
    int countSubstrings(string s) {
        int l = s.length();
        vector<vector<bool>> mat(l, vector<bool> (l, 0));
        int cnt = 0;
        for(int k=0; k<l; k++){
            for(int i=0, j=k; j<l; i++,j++){
                if(i == j){
                    mat[i][j] = 1;
                    cnt++;
                }
                else if(j - i == 1){
                    if(s[i] == s[j]){
                        mat[i][j] = 1;
                        cnt++;
                    } 
                }
                else{
                    if(s[i] == s[j] && mat[i+1][j-1] == 1){
                        mat[i][j] = 1;
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};
