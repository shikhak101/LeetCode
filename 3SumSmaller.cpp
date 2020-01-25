class Solution {
public:
    int res = 0;
    int helper(vector<int> nums, int t, int pos){
        int l = pos;
        int h = nums.size()-1;
        int sum =0;
        while(l<h){
            if(nums[l]+nums[h]<t){
                sum+=h-l;
                l++;
            }
            else{
                h--;
            }
        }
        return sum;
    }
    int threeSumSmaller(vector<int>& nums, int target) {
        if(nums.size()<3) return 0;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-2; i++)
            res+=helper(nums,target-nums[i],i+1);
        return res;
    }
};