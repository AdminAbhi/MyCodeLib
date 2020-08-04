class Solution {
public:
    bool checkPerfectNumber(int num) {
        if(num == 1) return 0;
        set<int> st;
        st.insert(1);
        for(int i=2; i*i <= num; i++){
            if(num % i == 0){
                st.insert(i);
                st.insert(num/i);
            }
        }
        int sum = 0;
        for(int i: st) sum += i;
        return num == sum;
    }
};
