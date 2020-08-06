class Solution {
public:
    long long fact(int n){
        long long res = 1;
        while(n){
            res = (res * n)%(1000000007);
            n--;
        }
        return res;
    }
    int numPrimeArrangements(int n) {
        vector<bool> prime(101, 1);
        for(int i=2; i<=50; i++){
            if(prime[i])
            for(int j=i+i; j<=100; j+=i){
                prime[j] = 0;
            }
        }
        int p = 0;
        for(int i=2; i<=n; i++){
            if(prime[i]) p++;
        }
        return (fact(n-p) * fact(p))%(1000000007);
    }
};
