class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> r;
        vector<int> c;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(matrix[i][j]==0){
                    r.push_back(i);
                    c.push_back(j);
                }
            }
        }
        for(int i=0; i<r.size(); i++){
            int row = r[i];
            for(int j=0; j<m; j++) matrix[row][j] = 0;
        }
        for(int i=0; i<c.size(); i++){
            int col = c[i];
            for(int j=0; j<n; j++) matrix[j][col] = 0;
        }
        
    }
};