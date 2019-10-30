class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int firstseen = 0;
        int secondseen = 0;
        for(auto x:nums) {
            firstseen = ~secondseen & (firstseen ^ x);
            secondseen = ~firstseen & (secondseen ^ x);
        }
        return firstseen;
    }
};