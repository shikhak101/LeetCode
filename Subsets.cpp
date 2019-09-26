class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int l = nums.size();
        vector<vector<int>> res;
        int subsetscount = pow(2,l);
        for(int i=0; i<subsetscount; i++) {
            vector<int> each;
            for(int j = 0; j<l; j++) {
                if((i & (1<<j)) > 0) each.push_back(nums[j]);
            }
            res.push_back(each);
        }
        return res;
    }
};