class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return -1;
        int prefix[n] = {0};
        int suffix[n] = {0};
        prefix[0] = 0;
        suffix[n-1] = 0;
        for(int i=1; i<n; i++) {
            prefix[i] = prefix[i-1] + nums[i-1];
        }
        for(int i = n-2; i>=0; i--) {
            suffix[i] = suffix[i+1] + nums[i+1];
        }
        int prefixsum = 0;
        int suffixsum = 0;
        for(int i=0; i<n; i++) {
            if(i==0) {
                prefixsum = 0;
                suffixsum = suffix[i];
            }
            else if(i == n-1) {
                prefixsum = prefix[i];
                suffixsum = 0;
            }
            else {
                prefixsum = prefix[i];
                suffixsum = suffix[i];
            }
            if(prefixsum == suffixsum) return i;
        }
        return -1;
    }
};