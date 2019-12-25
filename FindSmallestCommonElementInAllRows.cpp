class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        int res = -1;
        int c = 0;
        int n = mat.size();
        if(n==0) return res;
        int m = mat[0].size();
        map<int,int> mins;
        int maxel=-1;
        for(int i=0; i<n; i++) {
            mins.insert({i,0});
            if(maxel<mat[i][0]) {
                c = 1;
            }
            else if(maxel==mat[i][0]) {
                c++;
            }
            maxel = max(maxel,mat[i][0]);
        }
        int i = 0;
        while(c!=n) {
            int j=mins[i];
            while(j<m && mat[i][j]<maxel) {
                j++;
            }
            if(j==m) return -1;
            mins[i]= j;
            if(maxel == mat[i][j]) c++;
            if(maxel > mat[i][j]) c=1;
            maxel = max(mat[i][j],maxel);
            i++;
            if(i==n) i=0;
        }
        return maxel;
    }
};