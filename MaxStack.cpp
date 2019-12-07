class MaxStack {
public:
    /** initialize your data structure here. */
    stack<int> st;
    stack<int> maxst;
    MaxStack() {
        
    }
    
    void push(int x) {
        st.push(x);
        if(!maxst.empty()) {
            if(maxst.top()<x){
                maxst.push(x);
            }
            else maxst.push(maxst.top());
        }
        else maxst.push(x);
    }
    
    int pop() {
       int val = st.top();
        st.pop();
        maxst.pop();
        return val;
    }
    
    int top() {
        return st.top();
    }
    
    int peekMax() {
        return maxst.top();
    }
    
    int popMax() {
        int val = maxst.top();
        stack<int> temp;
        while(true){
            if(st.top() == val) {
                st.pop();
                maxst.pop();
                break;
            }
            temp.push(st.top());
            st.pop();
            maxst.pop();
        }
        while(!temp.empty()) {
            st.push(temp.top());
            if(!maxst.empty()) {
                if(maxst.top()<temp.top()){
                    maxst.push(temp.top());
                }
                else maxst.push(maxst.top());
            }
            else maxst.push(temp.top());
            temp.pop();
        }
        return val;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */