class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int p = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j =0; j<grid[i].size(); j++) {
                if(grid[i][j] == 0) continue;
                if(i>0) {
                    if(grid[i-1][j]==0) ++p;
                }
                else ++p;
                if(i<grid.size()-1) {
                    if(grid[i+1][j] == 0) ++p;
                }
                else ++p;
                if(j>0) {
                    if(grid[i][j-1] == 0) ++p;
                }
                else ++p;
                if(j<grid[i].size()-1) {
                    if(grid[i][j+1] == 0) ++p;
                }
                else ++p;
            }
        }
        return p;
    }
};