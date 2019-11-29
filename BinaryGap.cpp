class Solution {
public:
    int binaryGap(int N) {
        int num = 0;
        int maxgap = 0;
        int gap = 0;
        while(N>0) {
            int d = (num<<1) + (N & 1);
            if(gap == 0 && d == 1) gap++;
            else if(d == 0 && gap>0) gap++;
            else if(d == 1 && gap>0) {
                maxgap = max(maxgap,gap);
                gap = 1;
            }
            N = N >> 1;
        }
        return maxgap;
    }
};