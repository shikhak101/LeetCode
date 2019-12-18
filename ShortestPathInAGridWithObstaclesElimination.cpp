class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        if(grid.size()==0) return 0;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        vector<vector<pair<int,int>>> usedk(n,vector<pair<int,int>>(m,{0,0}));
        vector<vector<int>> visited(n,vector<int>(m,-1));
        if(grid[0][0]==1){
            if(k<=0) return -1;
            usedk[0][0] = {1,k-1};
            q.push({0,0});
        }
        else {
            usedk[0][0] = {1,k};
            q.push({0,0});
        }
        visited[0][0] = k-grid[0][0];
        while(!q.empty()) {
            pair<int,int> p = q.front();
            int a = p.first;
            int b = p.second;
            q.pop();
            int c = usedk[a][b].first;
            if(a==n-1 && b==m-1) return c-1;
            int curr = usedk[a][b].second;
            for(int i=0; i<4; i++) {
                int x = a + dirs[i].first;
                int y = b + dirs[i].second;
                if(x>=0 && y>=0 && x<n && y<m){
                    if(visited[x][y]>=curr-grid[x][y]) continue;
                    if(curr-grid[x][y]>=0) {
                        q.push({x,y});
                        visited[x][y] = curr-grid[x][y];
                        usedk[x][y] = {c+1,curr-grid[x][y]}; 
                    }
                }
            }
        }
        return -1;
    }
};