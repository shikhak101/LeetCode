class Solution {
public:
    static bool comp(int v1,int v2) {
        if(v1>v2) return true;
        return false;
    }
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        int sum = 0;
        for(int i=1; i<nums.size();i+=2) {
            sum += nums[i];
        }
        return sum;
    }
};