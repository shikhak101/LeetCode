class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int first_l = -1000;
        int second_l = -1000;
        int third_l = -1000;
        int first_s = 1000;
        int second_s = 1000;
        for( int i = 0; i< nums.size(); i++)
        {
            if(nums[i]> first_l) {
                third_l = second_l;
                second_l = first_l;
                first_l = nums[i];
            }
            else if(nums[i] > second_l) {
                third_l = second_l;
                second_l = nums[i];
            }
            else if(nums[i] > third_l) {
                third_l = nums[i];
            }
            if(nums[i] < first_s) {
                second_s  = first_s;
                first_s = nums[i];
            }
            else if(nums[i] < second_s) {
                second_s = nums[i];
            }
        }
        return (max(first_l*second_l*third_l, first_s*second_s*first_l));
    }
};