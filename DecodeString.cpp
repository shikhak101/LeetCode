class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        string res = "";
        while(i < s.length()) {
            if(isalpha(s[i])) {
                res += s[i];
                i++;
                continue;
            }
            if(isdigit(s[i])) {
                int num = 0;
                while(isdigit(s[i])) {
                    num = num * 10 + (s[i]-'0');
                    
                    i++;
                }
                int bracket = 1;
                i++;
                string innerstr = "";
                while(bracket>0) {
                    if(s[i] == '[') bracket++;
                    else if(s[i] == ']') bracket--;
                    if(bracket!=0) innerstr += s[i];
                    i++;
                }
                string temp = decodeString(innerstr);
                while(num > 0) {
                    res = res+ temp;
                    num--;
                }
            }
        } return res;
    }
};