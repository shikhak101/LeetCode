class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        int res = 0;
        vector<pair<int,int>> dirs = {{1,0},{0,1}};
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                int count = 0; int seen = 0;
                if(grid[i][j] == 0) continue;
                if(grid[i][j] == 1){
                    if(visited[i][j] == true) seen = 1;
                    count++;
                    visited[i][j] = true;
                }
                for(int k = 0; k<2; k++) {
                    int x = i+dirs[k].first;
                    int y = j+dirs[k].second;
                    while(x<n && y<m && x>=0 && y>=0) {
                        if(grid[x][y] == 1 && visited[x][y] == false) {
                            count++;
                            visited[x][y] = true;
                        }
                        else if(grid[x][y] == 1 && visited[x][y] == true) {
                            count++;
                            seen++;
                        }
                        x += dirs[k].first;
                        y += dirs[k].second;
                    }
                }
                if(count>1) res+=count-seen;
            }
        }
        return res;
    }
};