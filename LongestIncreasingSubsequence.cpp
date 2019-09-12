class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n < 2) return n;
        int maxval = 1;
        int cache[n] = {1};
        for(int i=0; i<n; i++) cache[i]=1;
        for(int i=1; i<n; i++) {
            for(int j = 0; j<i; j++) {
                if(nums[i] > nums[j]) {
                    if(cache[i]<cache[j]+1) cache[i]=cache[j]+1;
                    if(maxval < cache[i]) maxval = cache[i];
                }
            }
        }
        return maxval;
    }
};