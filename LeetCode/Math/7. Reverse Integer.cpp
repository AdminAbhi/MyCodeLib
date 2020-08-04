class Solution {
public:
    int reverse(int x) {
        if(x == 0) return 0;
        string n = to_string(abs(x));
        std::reverse(n.begin(), n.end());
        int num;
        try{
            num = stoi(n);    
        }
        catch(exception e){
            return 0;
        }
        return num*(x/abs(x));
    }
};
