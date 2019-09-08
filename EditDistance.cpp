class Solution {
public:
    int minDistance(string word1, string word2) {
        int mat[word1.length()+1][word2.length()+1] = {};
        int c = 0;
        for(int i = 0; i<= word1.length(); i++) {
            mat[i][0] = c;
            c++;
        }
        c = 0;
        for(int j = 0; j<= word2.length(); j++) {
            mat[0][j] = c;
            c++;
        }
        for(int i = 1; i<=word1.length(); i++) {
            for(int j=1; j<=word2.length(); j++) {
                if(word1[i-1] == word2[j-1]) {
                    mat[i][j] = mat[i-1][j-1];
                }
                else {
                    mat[i][j] = min(min(mat[i][j-1], mat[i-1][j]),mat[i-1][j-1]) +1;
                }
            }
        }
        return mat[word1.length()][word2.length()];
    }
};