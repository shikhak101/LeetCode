class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        int res = 0;
        int currsum = 0;
        unordered_map<int,int> m = {{0,1}};
        for(int i=0; i<n; i++){
            currsum+=nums[i]%2;
            if(currsum>=k) res += m[currsum-k];
            m[currsum]++;
        }
        return res;
    }
};