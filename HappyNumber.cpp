class Solution {
public:
    bool isHappy(int n) {
        if(n == 1) return true;
        set<int> s;
        s.insert(n);
        return check(n,s);
    }
    bool check(int n, set<int> s) {
        if(n == 1) return true;
        int sumsq = 0;
        while(n>0) {
            int d = n%10;
            sumsq += d*d;
            n = n/10;
        }
        if(s.find(sumsq) != s.end()) return false;
        s.insert(sumsq);
        return check(sumsq,s);
        
    }
};