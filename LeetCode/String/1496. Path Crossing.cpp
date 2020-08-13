class Solution {
public:
    bool isPathCrossing(string path) {
        int y = 0, x = 0;
        set<pair<int, int>> st;
        st.insert({0, 0});
        for(char c: path){
            if(c == 'N') y++;
            else if(c == 'S') y--;
            else if(c == 'E') x++;
            else x--;
            if(st.find({x,y}) != st.end()) return 1;
            st.insert({x,y});
        }
        return 0;
    }
};
