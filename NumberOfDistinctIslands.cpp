class Solution {
public:
    int numDistinctIslands(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n==0) return 0;
        int m = grid[0].size();
        if(m==0) return 0;
        set<vector<int>> st;
        vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
        for(int i=0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1){
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    vector<int> v;
                    while(!q.empty()){
                        int a = q.front().first;
                        int b = q.front().second;
                        q.pop();
                        for(int k=0; k<4; k++){
                            int x = a+dirs[k].first;
                            int y = b+dirs[k].second;
                            if(x>=0 && y>=0 && x<n && y<m && grid[x][y]==1){
                                grid[x][y] = 0;
                                v.push_back(k+1);
                                q.push({x,y});
                            }
                        }
                        v.push_back(0);
                    }
                    if(v.size()>0)
                        st.insert(v);
                }
            }
        }
        return st.size();
    }
};