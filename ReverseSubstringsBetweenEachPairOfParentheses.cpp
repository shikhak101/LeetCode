class Solution {
public:
    string reverseParentheses(string s) {
        string res = "";
        if(s.length()==0) return res;
        stack<char> st;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ')') {
                queue<char> q;
                while(!st.empty() && st.top()!='(') {
                    q.push(st.top());
                    st.pop();
                }
                if(!st.empty() && st.top()=='(') st.pop();
                while(!q.empty()) {
                    st.push(q.front());
                    q.pop();
                }
            }
            else {
                st.push(s[i]);
            }
        }
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};