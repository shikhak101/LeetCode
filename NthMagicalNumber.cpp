class Solution {
public:
    int gcd(int a, int b) {
        if(a==0) return b;
        return gcd(b%a,a);
    }
    int nthMagicalNumber(int N, int A, int B) {
        int res = 0;
        int minL = A/gcd(A,B) * B;
        long long int s = 0; long long int e = (long) pow(10,15);
        while(s<e) {
            long long int mid = s+(e-s)/2;
            if(mid/A + mid/B - mid/minL < N) s = mid+1;
            else e = mid;
        }
        res =  s%1000000007;
        return res;
    }
};