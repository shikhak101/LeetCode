class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        for(int i=0; i<n; i++) {
            int curr = 0;
            for(int j = i; j<n; j++) {
                curr += nums[j];
                if(curr == k) {
                    res = max(res,(j-i+1));
                }
            }
        }
        return res;
    }
};