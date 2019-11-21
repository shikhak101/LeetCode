class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int i=0;
        for(int j = i+1; j<s.length(); j++) {
            if(s[j] == s[i]) {
                int k1 = i; int k2 = j;
                while(k1<k2) {
                    if(s[k1]==s[j]){ k1++; j++; }
                    else break;
                }
                if(k1 == k2){
                    string subs = s.substr(i,k2);
                    string s1 = subs;
                    while(s1.length() <= s.length()){
                        if(s1 == s) return true;
                        if(s1 != s.substr(0,s1.length())) break;
                        s1 += subs;
                    }
                }
                j = k2;
            }
        }
        return false;
    }
};