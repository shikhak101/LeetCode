class Solution {
public:
    bool backtrack(string s, string t, int s1, int t1) {
        if(s1 == s.length()) {
            return true;
        }
        bool b = false;
        for(int i=t1; i<t.length(); i++) {
            if(t[i] == s[s1]) {
                b = backtrack(s,t,s1+1,i+1);
                if(b == true) return b;
            }
        }
        return b;
    }
    bool isSubsequence(string s, string t) {
        if(s.length() == 0 && t.length() == 0) return true;
        if(t.length() == 0) return false;
        if(s.length() == 0) return true;
        return backtrack(s,t,0,0);
    }
};