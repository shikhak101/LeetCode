class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        int n = A.size();
        if(n<2) return n;
        int res = 1;
        int i = 1;
        while(i<n){
            int check = 0;
            if(A[i-1]==A[i]){
                i++;
                continue;
            }
            if(A[i-1]<A[i]) check = 1;
            int start = i-1;
            i++;
            while(i<n){
                if(check == 1 && A[i-1]>A[i]){
                    check = 0;
                    i++;
                }
                else if(check == 0 && A[i-1]<A[i]){
                    check = 1;
                    i++;
                }
                else break;
            }
            int end = i-1;
            res = max(res,end-start+1);
        }
        return res;
    }
};