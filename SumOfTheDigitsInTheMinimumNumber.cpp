class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int minelement = INT_MAX;
        for(auto x:A) {
            minelement = min(minelement,x);
        }
        int sum = 0;
        while(minelement > 0) {
            int d = minelement%10;
            sum += d;
            minelement = minelement/10;
        }
        if(sum%2 == 0) return 1;
        return 0;
    }
};