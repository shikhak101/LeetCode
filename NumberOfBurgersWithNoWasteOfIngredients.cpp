class Solution {
public:
    vector<int> numOfBurgers(int t, int c) {
        vector<int> res;
        if(t%2 == 1) return res;
        long long int small = t/2;
        long long int jumbo = 0;
        long long int diff = small - c;
        if(diff<0) return res;
        small -= (2*diff);
        jumbo += diff;
        if(small >= 0 && jumbo >= 0 && small*2+jumbo*4 == t && small+jumbo-c == 0){
            res.push_back(jumbo);
            res.push_back(small);
            return res;
        }
        return res;
    }
};