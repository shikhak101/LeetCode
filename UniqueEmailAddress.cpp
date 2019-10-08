class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> st;
        for(auto s:emails) {
            string t = "";
            int plus =0;
            for(int i=0; i<s.length(); i++) {
                if(s[i] == '@') {
                    t += s.substr(i,s.length()-i);
                    st.insert(t);
                }
                else if(plus == 1) continue;
                else if(s[i] == '.'){
                    continue;
                }
                else if(s[i] == '+') {
                    plus = 1;
                }
                else {
                    t += s[i];
                }
            }
        }
        return st.size();
    }
};