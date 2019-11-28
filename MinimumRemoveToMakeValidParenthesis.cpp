class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<char> st;
        string res = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i]!='(' && s[i]!=')') {
                res += s[i];
            }
            else {
                if(s[i] == ')' && st.empty()) continue;
                if(s[i] == ')') {
                    st.pop();
                    res += s[i];
                }
                if(s[i] == '(') {
                    st.push(s[i]);
                    res += s[i];
                }
            }
        }
        int c = st.size();
        for(int i=res.length()-1; i>=0, c>0; i--) {
            if(res[i] == '(') {
                c--;
                res = res.substr(0,i)+res.substr(i+1,res.length());
            }
        }
        return res;
    }
};