class Solution {
public:
    int res = 0;
    vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    void findpath(vector<vector<int>> g, vector<vector<bool>>& vis,int ci,int cj, int n, int m, int visnodes, int c){
        if(g[ci][cj] == 2) {
            if(visnodes==c) res++;
            return;
        }
        for(int i=0; i<4; i++) {
            int x = ci+dirs[i].first;
            int y = cj+dirs[i].second;
            if(x>=0 && y>=0 && x<n && y<m && g[x][y]!=-1  && vis[x][y]==false) {
                vis[x][y] = true;
                visnodes++;
                findpath(g,vis,x,y,n,m,visnodes,c);
                visnodes--;
                vis[x][y] = false;
            }
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return res;
        int m = grid[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,false));
        int x = 0;
        int y = 0;
        int count =0;
        for(int i=0; i<n; i++) {
            int j=0;
            for(j=0; j<m; j++) {
                if(grid[i][j]!=-1) count++;
                if(grid[i][j]==1){
                    x = i; y = j;
                }
            }
        }
        int visnodes = 1;
        vis[x][y] = true;
        findpath(grid,vis,x,y,n,m,visnodes,count);
        return res;
    }
};