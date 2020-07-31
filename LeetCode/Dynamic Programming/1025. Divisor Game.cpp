class Solution {
public:
    bool canWin(int N, unordered_map<int, bool> &mp){
        if(N <= 1) 
            return false;
        if(mp.find(N) != mp.end()) 
            return mp[N];
        
        for(int x=1; x <= N/2; x++){
            if(N % x == 0){
                if(!canWin(N-x, mp)){
                    mp[N] = true;
                    return true;
                }
            }
        }
        mp[N] = false;
        return false;
    }
    bool divisorGame(int N) {
        unordered_map<int, bool> mp;
        return canWin(N, mp);
    }
    
    // Hack
    //bool divisorGame(int N) {
    //    return N % 2 == 0;
    //}
};