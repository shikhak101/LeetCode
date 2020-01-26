class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.length()==0) return 0;
        string revs = "";
        for(int i=s.length()-1; i>=0; i--){
            revs+=s[i];
        }
        if(s==revs) return 1;
        else return 2;
    }
};