class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        for(int i=0; i<A.size(); i++){
            int j=0, k=A[i].size()-1;
            while(j<=k){
                if(A[i][j]==A[i][k]){
                    if(A[i][j]==0) {
                        A[i][j] = 1;
                        A[i][k] = 1;
                    }
                    else {
                        A[i][j]=0;
                        A[i][k]=0;
                    }
                }
                j++; k--;
            }
        }
        return A;
    }
};