class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<long long>> count(n,vector<long long>(m,0));
        count[0][0] = 1;
        for(int i=0; i<n; i++)  {
            for(int j=0; j<m; j++) {
                if(obstacleGrid[i][j] == 1) {
                    count[i][j] = 0;
                    continue;
                }
                if(i>0) {
                    count[i][j] = count[i-1][j];
                }
                if(j>0) {
                    count[i][j] += count[i][j-1];
                }
            }
        }
        return (int)count[n-1][m-1];
    }
};