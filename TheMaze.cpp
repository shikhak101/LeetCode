class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        if(maze.size() == 0) return false;
        vector<vector<bool>> visited(maze.size(),vector<bool>(maze[0].size(),false));
        queue<pair<int,int>> q;
        vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
        q.push(make_pair(start[0],start[1]));
        visited[start[0]][start[1]] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            if(p.first == destination[0] && p.second == destination[1]) return true;
            for(int i=0; i<4; i++){
                
                int x = p.first + dirs[i].first;
                int y = p.second + dirs[i].second;
                while(x<maze.size() && y<maze[0].size() && x>=0 && y>=0 && maze[x][y]==0) {
                    x += dirs[i].first;
                    y += dirs[i].second;
                }
                if(!visited[x-dirs[i].first][y-dirs[i].second]) {
                    q.push(make_pair(x-dirs[i].first,y-dirs[i].second));
                    visited[x-dirs[i].first][y-dirs[i].second] = true;
                }
            }
        }
        return false;
    }
};