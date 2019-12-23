class Solution {
public:
    void backtrack(vector<int> nums, int i, set<vector<int>>& st) {
        if(i==nums.size()) {
            st.insert(nums);
            return;
        }
        for(int k = i; k<nums.size(); k++) {
            swap(nums[k],nums[i]);
            backtrack(nums,i+1,st);
            swap(nums[k],nums[i]);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        if(nums.size()==0) return res;
        set<vector<int>> st;
        backtrack(nums,0,st);
        for(auto x:st) {
            res.push_back(x);
        }
        return res;
    }
};