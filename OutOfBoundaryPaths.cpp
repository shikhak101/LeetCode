class Solution {
public:
    vector<pair<int,int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};
    int helper(int m, int n, int N, int i, int j, vector<vector<vector<int>>>& arr) {
        if(i==m || j==n || i<0 || j<0) return 1;
        if(N==0) return 0;
        if(arr[i][j][N]>=0)
            return arr[i][j][N];
        long long int val = 0;
        for(int k=0; k<4; k++) {
            int x = i+dirs[k].first;
            int y = j+dirs[k].second;
            val += helper(m,n,N-1,x,y,arr)%1000000007;            
        }
        arr[i][j][N] = val%1000000007;
        return arr[i][j][N]%1000000007;
    }
    int findPaths(int m, int n, int N, int i, int j) {
        if(n==0 || m==0 || N==0) return 0;
        vector<vector<vector<int>>> arr(m,vector<vector<int>>(n,vector<int>((N+1),-1))) ;
        return helper(m,n,N,i,j,arr);
    }
};