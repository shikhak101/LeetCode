class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        int res = count(nums.begin(),nums.end(),target);
        if(res>nums.size()/2) return true;
        return false;
    }
};