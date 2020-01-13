class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        if(n == 0) {
            vector<int> t; return t;
        }
        vector<int> res(n,0);
        int maxval = -1;
        for(int i=n-1; i>=0; i--) {
            res[i] = maxval;
            maxval = max(maxval,arr[i]);
        }
        return res;
    }
};