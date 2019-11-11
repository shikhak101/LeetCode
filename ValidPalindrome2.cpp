class Solution {
public:
    bool validPalindrome(string s) {
        if(s.length() == 0) return true;
        int k = 0;
        int i=0;
        int j = s.length()-1;
        int idxi = 0;
        int idxj = 0;
        while(i<j){
            if(s[i]!=s[j] && k>0) 
            {
                if(k==1){
                    k++;
                    if(s[idxi+1] == s[idxj]){
                        i = idxi+1;
                        j = idxj;
                    }
                    else return false;
                }
                else return false;
            }
            if(s[i]!=s[j] && k==0) {
                k++;
                idxi = i;
                idxj = j;
                if(s[i] == s[j-1]) j--;
                else if(s[i+1] == s[j]) i++;
            }
            else {
                i++; j--;
            }
        }
        return true;
    }
};