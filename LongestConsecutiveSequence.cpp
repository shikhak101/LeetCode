class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> st;
        for(auto x:nums){
            st.insert(x);
        }
        int res = 0;
        int curr = 0;
        int prev = 0;
        for(auto x:st) {
            if(curr == 0){
                curr = 1;
                prev = x;
            }
            else {
                if(prev+1 == x){
                    curr++;
                    prev = x;
                }
                else {
                    curr = 1;
                    prev = x;
                }
            }
            res = max(res,curr);
        }
        return res;
    }
};