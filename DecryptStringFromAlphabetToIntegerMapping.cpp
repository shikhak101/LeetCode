class Solution {
public:
    string freqAlphabets(string s) {
        string res = "";
        for(int i=s.length()-1; i>=0; i--) {
            if(s[i]=='#') {
                int i1 = s[i-2]-'0';
                int i2 = s[i-1]-'0';
                int val = i1*10 + i2;
                char c = val-1+'a';
                res = c+res;
                i-=2;
            }
            else{
                int i1 = s[i]-'0';
                char c = i1-1+'a';
                res = c+res;
            }
        }
        return res;
    }
};