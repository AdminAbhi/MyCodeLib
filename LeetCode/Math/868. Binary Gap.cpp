class Solution {
public:
    int binaryGap(int N) {
        int m = 0;
        int cnt = 0;
        while(N){
            int r = N % 2;
            if(r==1){
                m = max(m, cnt);
                cnt = 1;
            }
            else if(cnt) cnt++;
            N /= 2;
        }
        return m;
    }
};
