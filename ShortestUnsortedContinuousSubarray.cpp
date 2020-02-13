class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = INT_MAX;
        int j = INT_MIN;
        int check = 0;
        for(int x=0; x<n-1; x++){
            if(nums[x+1]<nums[x]) check = 1;
            if(check == 1) i = min(i,nums[x+1]);
        }
        check = 0;
        for(int x = n-1; x>0; x--){
            if(nums[x-1]>nums[x]) check = 1;
            if(check == 1) j = max(j,nums[x-1]);
        }
        int l = 0; int r = n-1;
        while(l<n && i>=nums[l]) l++;
        while(r>-1 && j<=nums[r]) r--;
        if(l>r) return 0;
        return r-l+1;
    }
};