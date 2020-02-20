class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int res = 0;
        int mindiff = INT_MAX;
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == target) return sum;
                if(sum<target){
                    j++;
                }
                else {
                    k--;
                }
                if(mindiff>abs(target-sum)){
                    mindiff = abs(target-sum);
                    res = sum;
                }
            }
        }
        return res;
    }
};