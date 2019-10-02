class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int mat[s.length()][s.length()] = {0};
        for(int i=s.length()-1; i>=0; i--) {
            for(int j = i; j<s.length(); j++) {
                if(i==j) mat[i][j]=1;
                else if(s[i]==s[j]) mat[i][j] = mat[i+1][j-1] + 2;
                else mat[i][j] = max(mat[i+1][j], mat[i][j-1]);
            }
        }
        return mat[0][s.length()-1];
    }
};