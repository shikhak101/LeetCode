class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size() == 1) return 0;
        int s = 0;
        int e = nums.size()-1;
        while(s<=e) {
            int mid = s+(e-s)/2;
            int check = 0;
            if(mid>0){
                if(nums[mid]>=nums[mid-1]) check = 1;
                else{
                    e = mid-1;
                    continue;
                }
            }
            if(mid<nums.size()-1){
                if(nums[mid]>=nums[mid+1]) check = 1;
                else {
                    s = mid+1;
                    continue;
                }
            }
            if(check == 1) return mid;
        }
        return 0;
    }
};