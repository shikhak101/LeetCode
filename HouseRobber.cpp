class Solution {
public:
    int rob(vector<int>& nums) {
        int maxsum = 0;
        int prevsum = 0;
        for(int i=0; i<nums.size(); i++) {
            int temp = maxsum;
            maxsum = max(maxsum, nums[i] + prevsum);
            prevsum = temp;
        }
        return maxsum;
    }
};