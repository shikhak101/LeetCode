class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        sort(nums.begin(),nums.end());
        int l = 0; int h = nums[n-1]-nums[0];
        while(l<h) {
            int mid = (l+h)/2;
            int c = 0; int j = 0;
            for(int i = 0; i<n; i++) {
                while(nums[i]-nums[j] > mid) j++;
                c += i-j;
            }
            if(c>=k) h = mid;
            else l = mid+1;
        }
        return l;
    }
};