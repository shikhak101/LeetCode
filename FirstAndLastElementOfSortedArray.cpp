class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = -1;
        int h = -1;
        int low = 0;
        int high = nums.size()-1;
        bool findLow = true;
        while(low<=high)
        {
            int mid = low + (high-low)/2;
            if(findLow == true){
                if((mid==0 || nums[mid-1]<target) && nums[mid]==target)
                {
                    l = mid;
                    findLow = false;
                    low = 0;
                    high = nums.size()-1;
                }
                else if(nums[mid]<target)
                {
                    low = mid+1;
                }
                else if(nums[mid]>=target)
                {
                    high = mid-1;
                }
            }
            else {
                if((mid==nums.size()-1 || nums[mid+1]>target) && nums[mid]==target)
                {
                    h = mid;
                    break;
                }
                else if(nums[mid]<=target)
                {
                    low = mid+1;
                }
                else if(nums[mid]>target)
                {
                    high = mid-1;
                }
            }
        }
        vector<int> res;
        res.push_back(l);
        res.push_back(h);
        return res;
    }
};