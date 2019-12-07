class Solution {
public:
    int minDistance(string word1, string word2) {
        if(word1.size()==0 || word2.size()==0) {
            return max(word1.size(),word2.size());
        }
        vector<vector<int>> mat(word1.size()+1,vector<int>(word2.size()+1,0));
        for(int i=0; i<=word1.length(); i++) {
            for(int j = 0; j<=word2.length(); j++) {
                if(i==0 || j==0) continue;
                if(word1[i-1] == word2[j-1]) {
                    mat[i][j] = mat[i-1][j-1]+1;
                }
                else mat[i][j] = max(mat[i-1][j],mat[i][j-1]);
            }
        }
        return word1.length()+word2.length()-2*mat[word1.length()][word2.length()];
    }
};