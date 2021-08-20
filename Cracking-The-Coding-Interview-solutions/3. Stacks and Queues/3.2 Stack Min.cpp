//https://leetcode.com/problems/min-stack/

class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> st;
    vector<int> min;
    MinStack() {
        ;;
    }
    
    void push(int val) {
        st.push_back(val);
        if(min.size() == 0 || min.back() >= val){
            min.push_back(val);
        }
    }
    
    void pop() {
        if(st.back() == min.back()){
            st.pop_back();
            min.pop_back();
        }
        else if(st.back() > min.back()){
            st.pop_back();
        }
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min.back();
    }
};
