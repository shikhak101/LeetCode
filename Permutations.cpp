class Solution {
public:
    void backtrack(vector<int> nums, int i, vector<vector<int>>& res) {
        if(i == nums.size()) {
            res.push_back(nums);
            return;
        }
        for(int k=i; k<nums.size(); k++) {
            swap(nums[k],nums[i]);
            backtrack(nums,i+1,res);
            swap(nums[k],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size() == 0) return res;
        vector<int> curr;
        backtrack(nums,0,res);
        return res;
    }
   
};