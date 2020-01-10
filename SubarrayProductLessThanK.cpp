class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0 || k<=1) return 0;
        int res = 0;
        int curr = 1;
        int j = 0;
        for(int i=0; i<n; i++) {
            curr = curr*nums[i];
            while(curr>=k) {
                curr /= nums[j];
                j++;
            }
            res += i-j+1;
        }
        return res;
    }
};