class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<vector<int>> grid;
    int helper(int r1, int c1, int c2, int n){
        int r2 = r1+c1-c2;
        if(r1>=n || c1>=n || r2>=n || c2>=n || grid[r1][c1]==-1 || grid[r2][c2]==-1) return INT_MIN;
        if(dp[r1][c1][c2] != -1) return dp[r1][c1][c2];
        if(r1 == n-1 && c1 == n-1) return grid[r1][c1];
        int ans = grid[r1][c1];
        if(c1!=c2) ans+=grid[r2][c2];
        int maxv = max(helper(r1,c1+1,c2+1,n), helper(r1+1,c1,c2+1,n));
        maxv = max(maxv,helper(r1,c1+1,c2,n));
        maxv = max(maxv,helper(r1+1,c1,c2,n));
        ans+=maxv;
        return dp[r1][c1][c2] = ans;
    }
    int cherryPickup(vector<vector<int>>& g) {
        int n = g.size();
        if(n==0) return 0;
        vector<vector<vector<int>>> mat(n,vector<vector<int>>(n,vector<int>(n,-1)));
        dp = mat;
        grid = g;
        int res = helper(0,0,0,n);
        return max(0,res);
    }
};