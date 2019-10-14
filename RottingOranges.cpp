class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int countorg = 0; 
        queue<pair<int,int>> q;
        queue<int> level;
        vector<vector<int>> visited;
        int n = grid.size(); int m = grid[0].size();
        for(int i=0; i<n; i++) {
            vector<int> t;
            for(int j = 0; j<m; j++) {
                if(grid[i][j] != 0) countorg++;
                if(grid[i][j] == 2) {
                    q.push(make_pair(i,j));
                    level.push(0);
                    t.push_back(1);
                }
                else t.push_back(0);
            }
            visited.push_back(t);
        }
        if(countorg == 0) return 0;
        int res = 0;
        int count1  = 0;
        int count2 = 0;
        int prevlevel = 0;
        int move = 0;
        while(!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            int l = level.front();
            level.pop();
            int x = p.first;
            int y = p.second;
            if(grid[x][y] == 2) count2++;
            else if(grid[x][y] == 1) count1++;
            int countfresh = 0;
            for(int k=0; k<4; k++) {
                int r = x + dx[k];
                int c = y + dy[k];
                if(r<n && c<m && r>=0 && c>=0 && grid[r][c] !=0 && visited[r][c]!=1) {
                    q.push(make_pair(r,c));
                    level.push(l+1);
                    visited[r][c] = 1;
                    if(grid[r][c] == 1) countfresh++;
                }
            }
            if(prevlevel == l && countfresh>0){
                move = 1;
            }
            else if(prevlevel != l || q.empty()) {
                if(move == 1) ++res;
                prevlevel = l;
                if(countfresh>0)move = 1;
                else move = 0;
            }
        }
        
        if(count2 == 0) return -1;
        if(count2 + count1 != countorg) return -1;
        return res;
    }
};