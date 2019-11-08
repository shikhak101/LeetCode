class Solution {
public:
    int balancedStringSplit(string s) {
        int res = 0;
        int l = 0; int r = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i] == 'L') l++;
            else if(s[i] == 'R') r++;
            if(l==r){
                res++;
                l = 0; r = 0;
            }
        }
        return res;
    }
};