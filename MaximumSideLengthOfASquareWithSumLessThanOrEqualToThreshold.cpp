class Solution {
public:
    int maxSideLength(vector<vector<int>>& mat, int threshold) {
        int n = mat.size();
        if(n==0) return 0;
        int m = mat[0].size();
        if(m==0) return 0;
        vector<vector<int>> row(n,vector<int>(m,0));
        vector<vector<int>> col(n,vector<int>(m,0));
        for(int i=0; i<n; i++) {
            for(int j = 0; j<m; j++) {
                row[i][j] = mat[i][j];
                col[i][j] = mat[i][j];
                if(i>0) row[i][j] += row[i-1][j];
                if(j>0) col[i][j] += col[i][j-1];
            }
        }
        int sq = min(n,m);
        int l = 0; 
        int h = sq;
        int res = 0;
        while(l<=h) {
            int size= l+ (h-l)/2;
            if(size==0){
                l=size+1;
                continue;
            }
            for(int i=0; i<(n-size+1); i++) {
                for(int j=0; j<(m-size+1); j++) {
                    int curr = mat[i][j];
                    if(curr>threshold) continue;
                    for(int k = 1; k<size; k++) {
                        curr += row[i+k][j+k] + col[i+k][j+k]-mat[i+k][j+k];
                        if(i>0) curr-=row[i-1][j+k];
                        if(j>0) curr-=col[i+k][j-1];
                        if(curr>threshold) break;
                    }
                    if(curr<=threshold){
                        res = max(res,size);
                        break;
                    }
                }
                if(res == size) break;
            }
            if(res == size) l = size + 1;
            else h = size-1;
        }
        return res;
    }
};