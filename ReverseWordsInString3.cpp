class Solution {
public:
    string revstr(string temp) {
        int nt = temp.length();
        string revtemp = "";
        for(int j = nt-1; j>=0; j--) {
            revtemp += temp[j];
        }
        return revtemp;
    }
    string reverseWords(string s) {
        int n = s.length();
        string result = "";
        string temp = "";
        string revtemp = "";
        for(int i = 0; i<n; i++) {
            if(s[i] != ' ') {
                temp += s[i];
            }
            else {
                revtemp = revstr(temp);
                result += revtemp + ' ';
                temp = "";
                revtemp = "";
            }
        }
        revtemp = revstr(temp);
        result += revtemp;
        return result;
    }
};