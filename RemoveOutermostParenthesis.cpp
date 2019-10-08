class Solution {
public:
    string removeOuterParentheses(string S) {
        stack<char> st;
        string res = "";
        string temp = "";
        if(S.length()==0) return res;
        temp += S[0];
        st.push(S[0]);
        
        for(int i=1; i<S.length(); i++) {
            temp += S[i];
            if(S[i]==')') {
                st.pop();
            }
            else {
                st.push('(');
            }
            if(st.empty()) {
                res += temp.substr(1,temp.length()-2);
                temp = "";
            }
            
        }
        return res;
    }
};