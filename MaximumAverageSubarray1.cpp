class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0.0;
        double res = -DBL_MAX;
        int n = nums.size();
        if(n<k || k == 0) return res;
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(i>=k-1){
                double avg = sum/k;
                res = max(res,avg);
                sum-=nums[i-k+1];
            }
        }
        return res;
    }
};