class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        int i=0;
        for(i=0; i<s.length(); i++) {
            if(s[i] == '6') {
                break;
            }
        }
        if(i==s.length()) return num;
        int a = 3 * pow(10,(s.length()-i-1));
        return num+a;
    }
};