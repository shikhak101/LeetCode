class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& A) {
        vector<vector<bool>> visited(A.size(),vector<bool>(A[0].size(),false));
        vector<pair<int,int>> dirs = {{0,1},{1,0},{0,-1},{-1,0}};
        priority_queue<tuple<int,int,int>> q;
        q.emplace(A[0][0],0,0);
        int maxval = A[0][0];
        visited[0][0] = true;
        while(!q.empty()) {
            auto [a,i,j] = q.top();
            q.pop();
            maxval = min(maxval,a);
            if(i == A.size()-1 && j == A[0].size()-1) {
                return maxval;
            }
            for(int k=0; k<4; k++) {
                int x = i+dirs[k].first;
                int y = j + dirs[k].second;
                if(x>=0 && y>=0 && x<A.size() && y<A[0].size() && visited[x][y] == false) {
                    q.emplace(A[x][y],x,y);
                    visited[x][y] = true;
                }
            }
        }
        return -1;
    }
};