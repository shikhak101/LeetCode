class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int sum = 0;
        if(!grid.empty() && !grid[0].empty())
        {
            vector<int> row(grid.size(),0);
            vector<int> col(grid.size(),0);
            for(int i = 0; i<grid.size(); i++)
            {
                for(int j=0; j<grid[0].size(); j++)
                {
                    row[i] = max(row[i], grid[i][j]);
                    col[j] = max(col[j], grid[i][j]);
                }
            }
            for(int i = 0; i<grid.size(); i++)
            {
                for(int j=0; j<grid[0].size(); j++)
                {
                    sum += min(row[i],col[j]) - grid[i][j];
                }
            }
        }
        return sum;
    }
};