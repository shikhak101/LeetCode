class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int res =0;
        for(int i=0; i<nums.size(); i++){
            if(nums[abs(nums[i])-1]<0) res = abs(nums[i]);
            else nums[abs(nums[i])-1] = nums[abs(nums[i])-1]*-1;
        }
        return res;
    }
};