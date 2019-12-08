class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        for(int c = 0; c<k; c++) {
            int v = grid[m-1][n-1];
            for(int i = m-1; i>=0; i--) {
                for(int j= n-2; j>=0; j--) {
                    grid[i][j+1] = grid[i][j];
                }
                if(i>0) {
                    grid[i][0] = grid[i-1][n-1];
                }
            }
            grid[0][0] = v;
        }
        return grid;
    }
};