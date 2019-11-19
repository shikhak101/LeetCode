class Solution {
public:
    bool hasAlternatingBits(int n) {
        int alt = (n & 1);
        n = (n >> 1);
        while(n) {
            if((n & 1) == 1 && alt == 1) return false;
            if((n & 1) == 0 && alt == 0) return false;
            alt = n & 1;
            n = (n >> 1);
        }
        return true;
    }
};