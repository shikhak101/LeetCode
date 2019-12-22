class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int res = 0;
        for(auto x:nums) {
            int digs = 0;
            while(x>0) {
                x=x/10;
                digs++;
            }
            if(digs%2 == 0) res++;
        }
        return res;
    }
};