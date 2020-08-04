class Solution {
public:
    int bitwiseComplement(int N) {
        if(N == 0) return 1;
        int num = 0;
        int idx = 0;
        while(N){
            int r = N % 2;
            if(r == 0) num += pow(2, idx);
            N /= 2;
            idx++;
        }
        return num;
    }
};
