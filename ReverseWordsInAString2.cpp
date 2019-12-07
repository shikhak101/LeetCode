class Solution {
public:
    void reverseWords(vector<char>& s) {
        if(s.size() == 0) return;
        stack<string> st;
        string word = "";
        for(int i=0; i<s.size(); i++) {
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
            st.push(word);
        }
        int k = 0;
        while(!st.empty()) {
            string t = st.top();
            for(int i=0; i<t.length(); i++) {
                s[k] = t[i];
                k++;
            }
            st.pop();
            if(!st.empty()){
                s[k] = ' ';
                k++;
            }
        }
        return;
    }
};