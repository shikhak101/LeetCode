class Solution {
public:
    int validSubarrays(vector<int>& nums) {
        //Approach 1
        // int res = nums.size();
        // for(int i=nums.size()-2; i>=0; i--) {
        //     for(int j = i+1; j<nums.size(); j++) {
        //         if(nums[i]<=nums[j]){
        //             res++;
        //         }
        //         else break;
        //     }
        // }
        // return res;
        
        //Approach 2
        int res = 0;
        stack<int> count;
        for(int i=0; i<nums.size(); i++) {
            while(!count.empty() && nums[i] < count.top()) count.pop();
            count.push(nums[i]);
            res+=count.size();
        }
        return res;
    }
};