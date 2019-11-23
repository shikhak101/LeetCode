class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& A) {
        int minsum = INT_MAX;
        for(int i = A.size()-2; i>=0; i--){
            for(int j = 0; j<A[0].size(); j++) {
                int val = A[i+1][j];
                if(j>0) {
                    val = min(val, A[i+1][j-1]);
                }
                if(j<A[0].size()-1) {
                    val = min(val,A[i+1][j+1]);
                }
                A[i][j] += val;
            }
        }
        for(int i=0; i<A[0].size(); i++) {
            minsum = min(minsum,A[0][i]); 
        }
        return minsum;
    }
};