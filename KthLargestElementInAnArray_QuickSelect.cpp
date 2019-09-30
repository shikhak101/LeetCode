class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
       return solve(nums, nums.size()-k+1, 0, nums.size()-1);
    }
    int solve(vector<int>& nums, int k, int start, int end) {
        int n = end-start+1;
        int y = start + rand()%n;
        swap(nums[y],nums[end]);
        int pos = partition(nums, start, end);
        if(pos == k-1) return nums[pos];
        if(pos<k-1) return solve(nums,k,pos+1,end);
        return solve(nums,k,start,pos-1);
    }
    int partition(vector<int>& nums, int start, int end) {
        int pivot = end;
        int large = start;
        for(int i=start;i<end+1; i++) {
            if(nums[i]<nums[pivot]) {
                swap(nums[i],nums[large]);
                large++;
            }
        }
        swap(nums[pivot],nums[large]);
        return large;
    }
};