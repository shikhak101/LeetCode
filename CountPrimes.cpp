class Solution {
public:
    int countPrimes(int n) {
        if(n<=2) return 0;
        if(n == 3) return 1;
        int res = 1;
        for(int i=3; i<n; i++){
            int num = i;
            int check = 0;
            for(int j=2; j<=sqrt(num); j++){
                if(num%j == 0) {
                    check=1;
                    break;
                }
            }
            if(check == 0) res++;
        }
        return res;
    }
};