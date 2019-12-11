class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        long long num = 0;
        vector<bool> res;
        for(int i=0; i<A.size(); i++) {
            num = num * 2 + A[i];
            if(num%5 == 0) res.push_back(true);
            else res.push_back(false);
            num%=5;
        }
        return res;
    }
};