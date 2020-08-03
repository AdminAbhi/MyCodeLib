class Solution {
public:
    vector<int> diStringMatch(string S) {
        int l = S.length();
        vector<int> num(l+1);
        int low = 0;
        int high = l;
        for(int i=0; i<l; i++){
            if(S[i] == 'I') num[i] = low++;
            else num[i] = high--;
        }
        num[l] = low;
        return num;
    }
};
