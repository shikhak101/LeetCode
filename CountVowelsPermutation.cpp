class Solution {
public:
    int countVowelPermutation(int n) {
        long long int ca = 1;
        long long int ce = 1;
        long long int ci = 1;
        long long int co = 1;
        long long int cu = 1;
        int count = 1;
        while(count < n) {
            count++;
            long long int newca = (ce+ci+cu)%(1000000007);
            long long int newce = (ca+ci)%(1000000007);
            long long int newci = (ce+co)%(1000000007);
            long long int newco = (ci)%(1000000007);
            long long int newcu = (ci+co)%(1000000007);
            ca = newca;
            ce = newce;
            ci = newci;
            co = newco;
            cu = newcu;
        }
        return (ca+ce+ci+co+cu)%1000000007;
    }
};