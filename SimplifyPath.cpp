class Solution {
public:
    string simplifyPath(string path) {
        string res = "";
        string word = "";
        stack<string> st;
        for(int i=0; i<path.length()+1; i++) {
            if(i == path.length() || path[i] == '/') {
                if(word.length()==0 || word == ".") {
                    word = "";
                    continue;
                }
                if(word == "..") {
                    if(!st.empty())
                        st.pop();
                }
                else if(word.size()>0) {
                    st.push(word);
                }
                word = "";
            }
            else{
                word += path[i];
            }
        }
        while(!st.empty()) {
            res = "/" + st.top() + res;
            st.pop();
        }
        if(res.length() == 0) return "/";
        return res;
    }
};