class Solution {
public:
    int fib(int N) {
        if(N == 0) return 0;
        if(N == 1) return 1;
        int prev1 = 0;
        int prev2 =1;
        int result = prev1 + prev2;
        for(int i = 2; i<N; i++) {
            prev1 = prev2;
            prev2 = result;
            result = prev1+prev2;
        }
        return result;
    }
};