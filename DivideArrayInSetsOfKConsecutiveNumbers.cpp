class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if(n%k != 0 || n<k) return false;
        map<int,int> m;
        for(auto x:nums) {
            if(m.find(x) == m.end()) {
                m.insert({x,1});
            }
            else m[x]++;
        }
        for(int i=0; i<n/k; i++) {
            int check = 0;
            int nextval = -1;
            int count = 0;
            for(auto x:m) {
                if(x.second == 0 && check == 0){
                    continue;
                }
                else if(x.second == 0 && check == 1) {
                    return false;
                }
                else if(check == 1 && x.first != nextval) {
                    return false;
                }
                check = 1;
                nextval = x.first+1;
                m[x.first]--;
                count++;
                if(count == k) {
                    break;
                }
            }
        }
        return true;
    }
};