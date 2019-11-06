class Solution {
public:
    bool rotateString(string A, string B) {
        if(A.length()!=B.length()) return false;
        if(A.length() == 0) return true;
        string s = A+A;
        int j=0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == B[j]) j++;
            else if(s[i]!=B[j]) {
                i=i-j;
                j=0; 
            }
            if(j==B.length()) return true;
        }
        return false;
    }
};