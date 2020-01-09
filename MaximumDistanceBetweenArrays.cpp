class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        if(arrays.size() == 0) return 0;
        int res = INT_MIN;
        int maxv = INT_MIN;
        int secmax = INT_MIN;
        int minv = INT_MAX;
        int secmin = INT_MAX;
        for(int i=0; i<arrays.size(); i++) {
            int n = arrays[i].size();
            if(arrays[i][0]<minv) {
                secmin = minv;
                minv = arrays[i][0];
            }
            else if(arrays[i][0] <secmin) {
                secmin = arrays[i][0];
            }
            if(arrays[i][n-1]>maxv) {
                secmax = maxv;
                maxv = arrays[i][n-1];
            }
            else if(arrays[i][n-1]>secmax) {
                secmax = arrays[i][n-1];
            }
        }
        if(maxv == minv) return 0;
        for(int i=0; i<arrays.size(); i++) {
            int n = arrays[i].size();
            if(arrays[i][n-1] == maxv) {
                res = max(res, abs(arrays[i][0]-secmax));
            }
            else {
                res = max(res, abs(arrays[i][0]-maxv));
            }
            if(arrays[i][0] == minv) {
                res = max(res, abs(arrays[i][n-1]-secmin));
            }
            else {
                res = max(res, abs(arrays[i][n-1]-minv));
            }
        }
        return res;
    }
};