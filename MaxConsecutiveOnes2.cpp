class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone = 0;
        int currone = 0;
        int zeros = 0;
        int loc = 0;
        for(int i=0; i<nums.size(); i++) {
            int x = nums[i];
            if(x == 1){
                currone++;
            }
            else if(x == 0 && zeros == 0){
                zeros++;
                currone++;
                loc = i;
            }
            else if(x==0 && zeros>0){
                maxone = max(maxone,currone);
                zeros = 1;
                currone = i-loc;
                loc = i;
            }
        }
        return max(maxone,currone);
    }
};