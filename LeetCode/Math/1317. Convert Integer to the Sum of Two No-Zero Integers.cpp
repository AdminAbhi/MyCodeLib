class Solution {
public:
    bool have0(int n){
        while(n){
            if(n % 10 == 0) return 0;
            n /= 10;
        }
        return 1;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i=1; i<=n/2; i++){
            if(have0(i) && have0(n-i)) return {i, n-i};
        }
        return {1, 1};
    }
};
