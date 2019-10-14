class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        vector<int> res;
        int j = 0;
        int p = -1;
        int maxval;
        for(int i = k-1; i<a.size(); i++) {
            if(j>p) {
                maxval = INT_MIN;
                for(int t = i-1; t>=j; t--) {
                    a[t] = max(a[t],a[t+1]);
                }
                p = i;
            }
            maxval = max(a[i],maxval);
            res.push_back(max(maxval,a[i-k+1]));
            j++;
        }
        return res;
    }
};