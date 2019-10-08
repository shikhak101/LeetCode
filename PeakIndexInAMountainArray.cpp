class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int maxval = INT_MIN; int res = 0;
        for(int i=0; i<A.size(); i++) {
            if(maxval<A[i]) {
                maxval = A[i];
                res = i;
            }
        }
        return res;
    }
};