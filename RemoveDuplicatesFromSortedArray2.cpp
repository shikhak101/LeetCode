class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        map<int,int> m;
        for(int i=0; i<n; i++) {
            if(m.find(nums[i])==m.end()) {
                m.insert({nums[i],1});
            }
            else m[nums[i]]++;
        }
        nums.clear();
        for(auto x:m) {
            cout<<x.first<<","<<x.second<<endl;
            if(x.second >1) {
                nums.push_back(x.first);
                nums.push_back(x.first);
            }
            else nums.push_back(x.first);
        }
        return nums.size();
    }
};