class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        int n = nums.size();
        if(n==0) return nums;
        int m = nums[0].size();
        if(n*m != r*c) return nums;
        vector<vector<int>> res;
        int x = 0; int y = 0;
        for(int i=0; i<r; i++) {
            vector<int> t;
            for(int j=0; j<c; j++) {
                t.push_back(nums[x][y]);
                y++;
                if(y==m) {
                    y=0;
                    x++;
                }
            }
            res.push_back(t);
        }
        return res;
    }
};