class Solution {
public:
    bool confusingNumber(int N) {
        map<int,int> m;
        m.insert({1,1});
        m.insert({6,9});
        m.insert({9,6});
        m.insert({8,8});
        m.insert({0,0});
        int num = N;
        int newN = 0;
        while(num>0) {
            int d = num%10;
            if(m.find(d) != m.end()) {
                d = m[d];
            }
            else return false;
            newN = newN*10 + d;
            num = num/10;
        }
        if(newN == N) return false;
        return true;
    }
};