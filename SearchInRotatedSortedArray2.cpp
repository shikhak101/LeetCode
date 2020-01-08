class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.size() == 0) return false;
        int s = 0; int e = nums.size()-1;
        while(s<=e){
            int mid = s+ (e-s)/2;
            if(nums[mid] == target) return true;
            if(nums[mid]>nums[s]) {
                if(target<nums[mid] && target>=nums[s])
                    e = mid-1;
                else s = mid+1;
            }
            else if(nums[mid]==nums[s]) {
                if(nums[mid] == nums[e] && nums[e] == nums[s]) {
                    s = s+1;
                    e = e-1;
                }
                else if(nums[mid]==nums[e]) e = mid-1;
                else s = mid+1;
            }
            else {
                if(target>nums[mid] && target<=nums[e]) 
                    s = mid+1;
                else e = mid-1;
            }
        }
        return false;
    }
};