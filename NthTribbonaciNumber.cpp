class Solution {
public:
    int tribonacci(int n) {
        int res = 0;
        int t0 = 0;
        int t1 = 1;
        int t2 = 1;
        if(n==0) return 0;
        if(n<3) return 1;
        for(int i = 3; i<=n; i++) {
            res = t0+t1+t2;
            t0 = t1;
            t1 = t2;
            t2 = res;
        }
        return res;
    }
};