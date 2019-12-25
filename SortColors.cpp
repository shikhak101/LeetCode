class Solution {
public:
    void sortColors(vector<int>& nums) {
        int z =0; int t = nums.size()-1;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] == 0) {
                swap(nums[i],nums[z]); z++;
            }
            while(nums[i] == 2 && i<t) {
                swap(nums[i],nums[t]); t--;
                if(nums[i] == 0) {
                    swap(nums[i],nums[z]); z++;
                }
            }
        }
    }
};