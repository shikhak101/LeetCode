class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        for(int i=n-1; i>=0;i--){
            for(int j=m-1; j>=0; j--){
                int minval = INT_MAX;
                if(i<n-1){
                    minval = min(minval,grid[i+1][j]);
                }
                if(j<m-1){
                    minval = min(minval,grid[i][j+1]);
                }
                if(minval == INT_MAX) {
                    continue;
                }
                grid[i][j] += minval;
            }
        }
        return grid[0][0];
    }
};