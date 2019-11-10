class Solution {
public:
    int longestOnes(vector<int>& nums, int K) {
        int maxone = 0;
        int currone = 0;
        int zeros = 0;
        queue<int> loc;
        for(int i=0; i<nums.size(); i++) {
            int x = nums[i];
            if(x == 1){
                currone++;
            }
            else if(x == 0 && zeros < K){
                zeros++;
                currone++;
                loc.push(i);
            }
            else if(x==0 && zeros>=K){
                maxone = max(maxone,currone);
                zeros = K;
                if(loc.empty()) currone = 0;
                else {
                    int l = loc.front();
                    loc.pop();
                    currone = i-l;
                    loc.push(i);
                }
            }
        }
        return max(maxone,currone);
    }
};