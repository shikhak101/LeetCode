class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int res = 0;
        if(grid.size()==0) return res;
        if(grid[0].size()==0) return res;
        for(int i=grid.size()-1; i>=0; i--){
            for(int j = grid[0].size()-1; j>=0; j--){
                if(grid[i][j]>=0) break;
                res++;
            }
        }
        return res;
    }
};