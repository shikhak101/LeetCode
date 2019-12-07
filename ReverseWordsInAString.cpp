class Solution {
public:
    string reverseWords(string s) {
        if(s.length() == 0) return s;
        stack<string> st;
        string word = "";
        string res = "";
        for(int i=0; i<s.length(); i++) {
            if(s[i] == ' ') {
                if(word.length()>0)
                    st.push(word);
                word = "";
            }
            else {
                word += s[i];
            }
        }
        if(word.length()>0) {
            res += word;
            if(!st.empty()) res += " ";
        }
        while(!st.empty()) {
            res+= st.top();
            st.pop();
            if(!st.empty()) res += " ";
        }
        return res;
    }
};