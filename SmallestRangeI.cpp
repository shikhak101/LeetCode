class Solution {
public:
    int smallestRangeI(vector<int>& A, int K) {
        int maxval= INT_MIN;
        int minval = INT_MAX;
        for(int i=0; i<A.size(); i++) {
            minval = min(minval,A[i]);
            maxval = max(maxval,A[i]);
        }
        int res = (maxval - K) - (minval + K);
        if(res<0) return 0;
        return res;
    }
};