class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        map<int,int> m;
        int sum = 0;
        m.insert({0,-1});
        for(int i=0; i<n; i++){
            sum += nums[i];
            if(k!=0) sum = sum%k;
            if(m.find(sum)!=m.end()){
                if(i-m[sum]>1)
                    return true;
            }
            else m[sum] = i;
        }
        return false;
    }
};