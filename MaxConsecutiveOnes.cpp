class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxone = 0; 
        int currone = 0;
        for(auto x:nums) {
            if(x == 0){
                maxone = max(maxone,currone);
                currone = 0;
            }
            else currone++;
        }
        return max(maxone,currone);
    }
};