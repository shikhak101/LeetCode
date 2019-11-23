class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<pair<int,int>> dirs = {{1,0},{0,1}};
        queue<pair<int,int>> q;
        q.push({0,0});
        int res = 0;
        vector<vector<int>> count(n,vector<int>(m,0));
        count[0][0] = 1;
        for(int i=0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                if(i>0)
                    count[i][j] = count[i-1][j];
                if(j>0)
                    count[i][j] += count[i][j-1];
            }
        }
        return count[n-1][m-1];
    }
};