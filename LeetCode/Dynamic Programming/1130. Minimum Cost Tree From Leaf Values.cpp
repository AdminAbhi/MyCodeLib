class Solution {
public:
    
    pair<int, int> rec(vector<int> &arr, int l, int r, map<pair<int, int>, pair<int, int>> &mp){
        if(mp.find({l, r}) != mp.end()){
            return mp[{l, r}];
        }
        if(l == r){
            pair<int, int> c = {0, arr[l]};
            mp[{l, r}] = c;
            return c;
        }
        
        pair<int, int> gc = {INT_MAX, INT_MIN};
        
        for(int i=l; i<r; i++){
            pair<int, int> li = rec(arr, l, i, mp);
            pair<int, int> ri = rec(arr, i+1, r, mp);
            
            pair<int, int> a = {li.first + ri.first + li.second * ri.second, max(li.second, ri.second)};
            pair<int, int> b = {li.second * ri.second + li.first + ri.first, max(li.second, ri.second)};
            
            pair<int, int> c = a.first < b.first ? a : b;    
            if(gc.first > c.first) gc = c;
        }
        
        mp[{l, r}] = gc;
        return gc;
    }
    
    int mctFromLeafValues(vector<int> &arr) {
        map<pair<int, int>, pair<int, int>> mp;
        return rec(arr, 0, arr.size()-1, mp).first;
    }
};
