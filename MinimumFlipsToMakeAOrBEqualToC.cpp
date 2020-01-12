class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;
        while(a>0 || b>0 || c>0) {
            int a1=0;
            a1 = (a1<<1) +(a & 1);
            int b1=0;
            b1 = (b1<<1) +(b & 1);
            int c1=0;
            c1 = (c1<<1) +(c & 1);
            if(a1 == 1 && b1 == 1) {
                if(c1 == 0) res+=2;
            }
            else if(a1 == 1 || b1 == 1) {
                if(c1 == 0) res++;
            }
            else if(a1 == 0 && b1 == 0) {
                if(c1 == 1) res++;
            }
            a = a>>1;
            b = b>>1;
            c = c>>1;
        }
        return res;
    }
};