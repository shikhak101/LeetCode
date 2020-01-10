class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int res = 0;
        int n = nums.size();
        map<int,int> sum;
        int curr = 0;
        sum.insert({0,-1});
        for(int i=0; i<n; i++) {
            curr += nums[i];
            if(sum.find(curr-k) != sum.end() && i-sum[curr-k] > res) res = i-sum[curr-k];
            if(sum.find(curr)==sum.end()) sum.insert({curr,i});
        }
        return res;
    }
};