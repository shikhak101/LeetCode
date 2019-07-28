class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0) return s;
        int x = 0, y = 0, len = 1;
        int n = s.length();
        bool p[n][n] = {true};
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==j) p[i][j] = true;
                if(i == j-1) {
                    if(s[i] == s[j]) {
                        p[i][j] = true;
                        len = 2;
                        x=i; y=j;
                    }
                    else p[i][j] = false;
                }
                
            }
        }
        
        for(int k=0; k<n-1; k++)
        {
            int i = 0;
            for(int j=k+2; j<n; j++,i++)
            {   
                if(s[i]==s[j] && p[i+1][j-1] == true) {
                    p[i][j] = true;
                    if(len < (j-i+1))
                    {
                        len = j-i+1;
                        x=i; y=j;
                        
                    }
                }
                else p[i][j] = false;
            }
        }
        
        return s.substr(x,len);
    }
};