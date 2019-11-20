class Solution {
public:
    bool isPrime(int n){
        if(n == 1) return false;
        for(int i=2; i<n; i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int L, int R) {
        int res = 0;
        for(int i=L; i<=R; i++) {
            int n = i;
            int sets = 0;
            while(n>0) {
                sets += (n & 1);
                n = n >> 1;
            }
            if(isPrime(sets)) {
                res++;
            }
        }
        return res;
    }
};