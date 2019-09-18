class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        int dict[26] = {0};
        for(int i=0; i<s.length(); i++) {
            dict[s[i] - 'a'] ++;
            dict[t[i] - 'a'] --;
        }
        for(int i=0; i<26; i++) {
            if(dict[i] > 0) return false;
        }
        return true;
    }
};