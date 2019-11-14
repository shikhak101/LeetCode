class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        int i=nums.size()-1;
        while(k>0){
            k--;
            nums.insert(nums.begin(),nums[i]);
            nums.pop_back();
        }
    }
};