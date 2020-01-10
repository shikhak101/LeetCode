class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        if(n==0) return 0;
        priority_queue<int> pq;
        for(int i=0; i<n-1; i++) {
            for(int j = i+1; j<n; j++) {
                int diff = abs(nums[i]-nums[j]);
                if(pq.size()<k)
                    pq.push(diff);
                else if(pq.size()>=k && diff<pq.top()) {
                    pq.pop();
                    pq.push(diff);
                }
            }
        }
        return pq.top();
    }
};