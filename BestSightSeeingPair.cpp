class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        if(n==0) return 0;
        int res = 0;
        int maxval = A[0]-1;
        for(int i=1; i<n; i++){
            res = max(res, A[i]+maxval);
            maxval = max(A[i],maxval);
            maxval--;
        }
        return res;
    }
};