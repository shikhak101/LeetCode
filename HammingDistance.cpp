class Solution {
public:
    int hammingDistance(int x, int y) {
        int res =0;
        x = x^y;
        while(x) {
            x = x&(x-1);
            ++res;
        }
        return res;
    }
};