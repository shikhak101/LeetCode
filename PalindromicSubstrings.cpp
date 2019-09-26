class Solution {
public:
    int checkpalindrome(string s1) {
        int i=0; 
        int j = s1.length()-1;
        while(i<j){
            if(s1[i] != s1[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    int countSubstrings(string s) {
        int count = s.length();
        for(int i = 2; i<s.length()+1; i++) {
            for(int j=0; j<=s.length()-i; j++) {
                int t = checkpalindrome(s.substr(j,i));
                if(t == 1) count++;
            }
        }
        return count;
    }
};