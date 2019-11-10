class Solution {
public:
    int titleToNumber(string s) {
        int k = 0; 
        int res = 0;
        for(int i = s.length()-1; i>=0; i--) {
            int c = s[i] - 'A' + 1;
            res += pow(26,k)*c;
            k++;
        }
        return res;
    }
};