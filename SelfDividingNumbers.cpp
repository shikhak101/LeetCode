class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left; i<=right; i++) {
            int num = i;
            while(num>0) {
                int d = num%10;
                if(d == 0 || i%d != 0) break;
                num = num/10;
            }
            if(num<=0) res.push_back(i);
        }
        return res;
    }
};