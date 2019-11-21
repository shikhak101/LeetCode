class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char,string> m;
        set<string> st;
        int j = 0;
        for(int i=0; i<pattern.length(); i++) {
            char c = pattern[i];
            string word = "";
            if(j>=str.length()) return false;
            while(j<str.length() && str[j]!=' ') {
                word += str[j];
                j++;
            }
            j++;
            if(m.find(c) == m.end()) {
                if(st.find(word) == st.end()){
                    m.insert({c,word});
                    st.insert(word);
                }
                else return false;
            }
            else {
                if(m[c] != word) return false;
            }
        }
        if(j<str.length()) return false;
        return true;
    }
};