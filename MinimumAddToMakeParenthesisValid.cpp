class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> st;
        int res = 0;
        for(int i=0; i<S.length(); i++) {
            if(S[i] == '(') {
                st.push('(');
            }
            else {
                if(!st.empty()) st.pop();
                else res++;
            }
        }
        return res+st.size();
    }
};