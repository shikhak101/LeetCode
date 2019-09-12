class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;
        int max = 0;
        int currlen = 1;
        int i = 0; 
        int j = 1;
        while(i < n && j < n) {
            if(nums[j-1] >= nums[j]) {
                currlen = j-i;
                if(max<currlen)
                    max = currlen;
                i = j;
            }
            else if(j == n-1) {
                currlen = j-i+1;
                if(max<currlen)
                    max = currlen;
                i = j;
            }
            j++;
        }
        return max;
    }
};