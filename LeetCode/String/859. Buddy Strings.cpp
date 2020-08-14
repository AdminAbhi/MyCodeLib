class Solution {
public:
    bool buddyStrings(string A, string B) {
        vector<int> h1(26,0);
        vector<int> h2(26,0);        
        int mx = 0;
        
        for(char c: A) mx = max(mx, ++h1[c-'a']);
        for(char c: B) h2[c-'a']++;
        for(int i=0; i<26; i++) if(h1[i] != h2[i]) return 0;
        
        if(A == B && mx > 1) return 1;
        else if(A == B) return 0;
        
        int d = 0;
        for(int i=0; i<A.length(); i++){
            if(A[i] != B[i]) d++;
            if(d > 2) return 0;
        }
        return d == 2;
    }
};
