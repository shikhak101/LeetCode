class Solution {
public:
    int maxgold= 0;
    vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    int n;
    int m;
    vector<vector<bool>> vis;
    vector<vector<int>> g;
    void dfs( int i, int j, int sum) {
        maxgold = max(maxgold,sum);
        vis[i][j]= true;
        for(int k=0; k<4; k++) {
            int x=i+dirs[k].first;
            int y=j+dirs[k].second;
            if(x>=0 && y>=0 && x<n && y<m && g[x][y]>0 && vis[x][y]==false) {
                dfs(x,y,sum+g[x][y]);
            }
        }
        vis[i][j] = false;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int n1 = grid.size();
        if(n1==0) return maxgold;
        int m1 = grid[0].size();
        vector<vector<bool>> vis1(n1,vector<bool>(m1, false));
        n = n1;
        m = m1;
        vis = move(vis1);
        g = move(grid);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(g[i][j]==0) continue;
                dfs(i,j,g[i][j]);
            }
        }
        return maxgold;
    }
};