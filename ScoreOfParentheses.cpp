class Solution {
public:
    int scoreOfParentheses(string S) {
        stack<int> st;
        int res = 0;
        for(int i=0; i<S.length(); i++) {
            if(S[i] == '(') {
                st.push(-1);
            }
            if(S[i] == ')') {
                if(st.top() == -1) {
                    st.pop();
                    st.push(1);
                }
                else{
                    int val = 0;
                    while(st.top()!=-1){
                        val+=st.top();
                        st.pop();
                    }
                    st.pop();
                    st.push(2*val);
                }                
            }
        }
        while(!st.empty()) {
            res+=st.top();
            st.pop();
        }
        return res;
    }
};