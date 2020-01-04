class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(nums[0]<nums[n-1]) return nums[0];
        int prev = nums[0]; int i = n-1;
        while(i>=0 && prev>=nums[i]){
            prev = nums[i];
            i--;
        }
        return prev;
    }
};