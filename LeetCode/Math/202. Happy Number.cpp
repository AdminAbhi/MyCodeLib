class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        st.insert(n);
        while(n!=1){
            int sum = 0;
            while(n){
                int r = n % 10;
                sum += r*r;
                n /= 10;
            }
            if(st.find(sum) != st.end()){
                return 0;
            }
            else{
                n = sum;
                st.insert(n);
            }
        }
        return 1;
    }
};
