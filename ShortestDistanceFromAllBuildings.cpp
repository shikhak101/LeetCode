class Solution {
public:
    int shortestDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        int res = -1;
        auto sum = grid;
        int w = 0;
        vector<pair<int,int>> dirs={{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++){
                if(grid[i][j]==1){
                    res = -1;
                    auto curr = grid;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while(!q.empty()){
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        for(int k = 0; k<4; k++){
                            int x = a+dirs[k].first;
                            int y = b+dirs[k].second;
                            if(x>=0 && y>=0 && x<n && y<m && grid[x][y] == w){
                                q.push({x,y});
                                grid[x][y]--;
                                curr[x][y] = curr[a][b]+1;
                                sum[x][y] += curr[x][y]-1;
                                if(res<0 || res>sum[x][y]) res = sum[x][y];
                            }
                        }
                    } w--;
                }
            }
        }
        return res;
    }
};