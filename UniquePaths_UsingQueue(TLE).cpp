class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<pair<int,int>> dirs = {{1,0},{0,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        int res = 0;
        vector<vector<int>> count(n,vector<int>(m,0));
        count[0][0] = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(int i=0; i<2; i++){
                int x = dirs[i].first + curr.first;
                int y = dirs[i].second + curr.second;
                if(x>=0 && y>=0 && x<n && y<m) {
                    if(x-1>=0)
                        count[x][y] = count[x-1][y];
                    if(y-1>=0)
                        count[x][y] += count[x][y-1];
                    q.push({x,y});
                }
            }
        }
        return count[n-1][m-1];
    }
};