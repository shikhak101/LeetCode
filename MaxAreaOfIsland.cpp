class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        if(grid.size() == 0) return 0;
        int maxsize = 0;
        vector<vector<bool>> visited(grid.size(),vector<bool>(grid[0].size(),false));
        queue<pair<int,int>> q;
        for(int i=0; i<grid.size(); i++) {
            for(int j = 0; j<grid[0].size(); j++) {
                if(grid[i][j] == 0 || visited[i][j] == true) continue;
                int size = 1;
                q.push({i,j});
                visited[i][j] = true;
                while(!q.empty()) {
                    auto curr = q.front();
                    q.pop();
                    for(int k=0; k<4; k++) {
                        int x = curr.first + dirs[k].first;
                        int y = curr.second + dirs[k].second;
                        if(x>=0 && y>=0 && x<grid.size() && y<grid[0].size() && grid[x][y]==1 && visited[x][y]==false) {
                            q.push({x,y});
                            visited[x][y] = true;
                            size++;
                        }
                    }
                }
                maxsize = max(maxsize,size);
            }
        }
        
        return maxsize;
    }
};