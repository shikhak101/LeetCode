class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        if(n==0) return 0;
        int curr = 1;
        for(int i=0; i<n; i++) {
            curr = 1;
            for(int j = i; j<n; j++) {
                curr *= nums[j];
                res = max(res,curr);
            }
        }
        return res;
    }
};