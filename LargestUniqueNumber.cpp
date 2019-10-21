class Solution {
public:
    int largestUniqueNumber(vector<int>& A) {
        int res = -1;
        int dict[2000] = {0};
        for(auto x:A) {
            dict[x]++;
        }
        int curr= 0;
        for(auto x:A) {
            if(dict[x] == 1){
                res = max(res,x);
            }
        }
        return res;
    }
};