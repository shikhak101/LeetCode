class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        int len1 = 0;
        int len2 = 0;
        int l = low;
        int h = high;
        int fl = 0; int fh = 0;
        while(l>0) {
            len1++;
            fl = l%10;
            l/=10;
        }
        while(h>0) {
            len2++;
            fh = h%10;
            h/=10;
        }
        for(int i=len1; i<=len2; i++) {
            while(i+fl<=10){
                int j = fl;
                int newn = 0;
                for(int k = 0; k<i; k++) {
                    newn = newn*10 + j;
                    j = j+1;
                }
                if(newn>=low && newn<=high) res.push_back(newn);
                if(newn>=high) break;
                fl++;
            }
            fl = 1;
        }
        return res;
    }
};