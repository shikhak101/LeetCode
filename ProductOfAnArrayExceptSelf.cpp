class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res;
        for(int i=0; i<nums.size(); i++) {
            if(i==0) res.push_back(1);
            else {
                res.push_back(res[i-1]*nums[i-1]);
            }
        }
        int prod = 1;
        for(int i=nums.size()-2; i>=0; i--) {
            prod = prod*nums[i+1];
            res[i] = res[i] * prod;
        }
        return res;
    }
};