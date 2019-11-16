class Solution {
public:
    bool isPrime(int N) {
        if(N<2) return false;
        for(int i=2; i<=sqrt(N); i++){
            if(N%i == 0) return false;
        }
        return true;
    }
    bool isPalindrome(int N) {
        string s = to_string(N);
        int i=0; int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++; j--;
        }
        return true;
    }
    int primePalindrome(int N) {
        while(true) {
            if(isPrime(N) && isPalindrome(N)){
                return N;
            }
            N++;
            if (10000000 < N && N < 100000000)
                N = 100000000;
        }
        return N;
    }
};