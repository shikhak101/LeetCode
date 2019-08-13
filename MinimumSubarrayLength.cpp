class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0, end = -1;
        int l = nums.size();
        int minlen = l+1;
        int sum = 0;
        while(start<l)
        {
            if(sum < s && end +1< l)
            {
                end++;
                sum += nums[end];
            }
            else { 
                sum -= nums[start];
                start++;
            }
            if(sum >= s && minlen > end-start+1) {
                minlen = end-start+1;
            }
            
        }
        if(minlen > l) return 0;
        return minlen;
    }
};