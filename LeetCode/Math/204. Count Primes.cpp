class Solution {
public: 
    int countPrimes(int n) {
        vector<bool> arr(n, 1);
        for(int i=2; i*i<n; i++){
            if(!arr[i]) continue;
            for(int j = i*i; j < n; j += i){
                arr[j] = 0;  
            } 
        }
        int cnt = 0;
        for(int i=2; i<n; i++){
            if(arr[i]) cnt++;
        }
        return cnt;
    }
};
