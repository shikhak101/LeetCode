class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;
        for(int i=0; i<num.length(); i++) {
            while(!st.empty() && k>0 && st.top()>num[i]) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        for(int i=0; i<k; i++) {
            if(!st.empty())
                st.pop();
        }
        string res = "";
        string zeros = "";
        while(!st.empty()) {
            char c = st.top();
            st.pop();
            if(c == '0') {
                zeros += '0';
            }
            else {
                res = c+zeros+res;
                zeros = "";
            }
        }
        if(res.size() == 0) return "0";
        return res;
    }
};