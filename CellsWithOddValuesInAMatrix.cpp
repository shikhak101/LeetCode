class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> mat(n,vector<int>(m,0));
        for(int i=0; i<indices.size(); i++){
            int x = indices[i][0];
            int y = indices[i][1];
            for(int c = 0; c<m; c++) {
                mat[x][c]++;
            }
            for(int r = 0; r<n; r++){
                mat[r][y]++;
            }
        }
        int res = 0;
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(mat[i][j]%2 == 1) res++;
            }
        }
        return res;
    }
};