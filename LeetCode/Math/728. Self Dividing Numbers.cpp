class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left; i<=right; i++){
            bool foo = 1;
            int n = i;
            while(n){
                int r = n % 10;
                if(r == 0 || i % r != 0){
                    foo = 0;
                    break;
                }
                n /= 10;
            }
            if(foo) res.push_back(i);
        }
        return res;
    }
};
