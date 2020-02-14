class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        int l1 = A.size();
        int l2 = B.size();
        int res = 0;
        vector<vector<int>> dp(l1+1,vector<int>(l2+1,0));
        for(int i=1;i<=l1; i++){
            for(int j=1; j<=l2; j++){
                if(A[i-1]==B[j-1]) dp[i][j] = dp[i-1][j-1]+1;
                res = max(res,dp[i][j]);
            }
        }
        return res;
    }
};