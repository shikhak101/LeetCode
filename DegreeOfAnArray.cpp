class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,pair<int,int>> m;
        map<int,int> count;
        int maxel = -1; int maxc = 0;
        for(int i=0; i<nums.size(); i++) {
            if(m.find(nums[i]) == m.end()) {
                m.insert({nums[i],{i,i}});
                count.insert({nums[i],1});
            }
            else {
                m[nums[i]].second = i;
                count[nums[i]]++;
            }
            if(maxc<count[nums[i]]) {
                maxc = count[nums[i]];
                maxel = nums[i];
            }
        }
        int res = nums.size();
        for(auto x:count) {
            if(x.second!=maxc) continue;
            res = min(res,m[x.first].second-m[x.first].first+1);
        }
        return res;
    }
};