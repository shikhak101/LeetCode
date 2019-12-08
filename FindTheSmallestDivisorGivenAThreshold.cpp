class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = 1000000;
        int res = INT_MAX;
        while(l<=r) {
            int mid = (l+r)/2;
            int sum = 0;
            for(auto x:nums) {
                sum += (x+(mid-1))/mid;
            }
            if(sum>threshold) {
                l = mid+1;
                continue;
            }
            else {
                if(res == mid) return res;
                res = min(res,mid);
                r = mid-1;
            }
        }
        return res;
    }
};