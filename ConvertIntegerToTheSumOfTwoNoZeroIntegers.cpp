class Solution {
public:
    bool nozero(int num) {
        while(num>0) {
            if(num%10 == 0) return false;
            num /=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int n1 = 1;
        int n2 = n-1;
        vector<int> res;
        while(true)
        {
            if(nozero(n1) && nozero(n2)) {
                res.push_back(n1);
                res.push_back(n2);
                return res;
            }
            else {
                n1++; n2--;
            }
        }
        return res;
    }
};