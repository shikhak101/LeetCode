class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return 0;
        map<int,int> m;
        for(int x:nums) m[x]++;
        int res = 0;
        for(auto x:m){
            if(m.find(x.first+1) != m.end()){
                res = max(res,x.second + m[x.first+1]);
            }
        }
        return res;
    }
};