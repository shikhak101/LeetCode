class Solution {
public:
    string convertToTitle(int n) {
        string s = "";
        if(n <= 26) {
            char ch = 'A'+n-1;
            return s+ch;
        } 
        while(n!=0){
            int d = n%26;
            if(d == 0) {
                s += 'Z';
                n = n-26;
            }
            else {
                char a = 'A'+d-1;
                s += a;
            }
            n = n/26;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};