class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        if(n==0) return res;
        for(int i=0; i<n; i++ ){
            int curr = 0;
            for(int j = i; j<n; j++) {
                curr += nums[j];
                if(curr == k) res++;
            }
        }
        return res;
    }
};