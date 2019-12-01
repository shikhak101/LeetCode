class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++) {
                if(matrix[i][j] ==0) continue;
                int minval = INT_MAX;
                if(i>0 && j>0) {
                    minval = min(minval,matrix[i][j-1]);
                    minval = min(minval,matrix[i-1][j-1]);
                    minval = min(minval,matrix[i-1][j]);
                    matrix[i][j] += minval;
                }
                res += matrix[i][j];
            }
        }
        return res;
    }
};