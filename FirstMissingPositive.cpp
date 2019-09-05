class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
        {
            while(i+1 != nums[i] && nums[i]>0 && nums[i] < nums.size()+1)
            {
                int new_loc = nums[i]-1;
                int old_loc = i;
                int temp = nums[old_loc];
                nums[old_loc] = nums[new_loc];
                nums[new_loc] = temp;
                if(nums[old_loc] == nums[new_loc]) break;
            }
        }
        
        for(int i = 0; i< nums.size(); i++)
        {
            if(nums[i] != i+1) return i+1;
        }
        return nums.size()+1;
    }
};