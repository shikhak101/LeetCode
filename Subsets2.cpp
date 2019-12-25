class Solution {
public:
    void backtrack(vector<int> nums,vector<vector<int>>& res, int pos, int n, vector<int>& curr){
        res.push_back(curr);
        for(int k=pos; k<n; k++) {
            if(k&&nums[k]==nums[k-1] && k>pos) continue;
            curr.push_back(nums[k]);
            backtrack(nums,res,k+1,n,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<int> curr;
        backtrack(nums,res,0,nums.size(),curr);
        return res;
    }
};