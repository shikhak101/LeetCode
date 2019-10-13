class Solution {
public:
    bool isIsomorphic(string s, string t) {
        set<char> tset;
        map<char,char> m;
        for(int i=0; i<s.length(); i++) {
            if(m.find(s[i]) == m.end()) {
                if(tset.find(t[i]) != tset.end()) {
                    return false;
                }
                m.insert(make_pair(s[i],t[i]));
                tset.insert(t[i]);
            }
            else {
                if(m[s[i]] != t[i]) return false;
            }               
        }
        return true;
    }
};