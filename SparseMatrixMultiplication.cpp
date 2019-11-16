class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> res(A.size(),vector<int>(B[0].size(),0));
        for(int i=0; i<res.size(); i++){
            for(int j = 0; j<res[i].size(); j++){
                int val1 = 0;
                for(int k = 0; k<B.size(); k++){
                    val1 += A[i][k]*B[k][j];
                }
                res[i][j] = val1;
            }
        }
        return res;
    }
};