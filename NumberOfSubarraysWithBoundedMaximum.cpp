class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        int n = A.size();
        if(n==0) return 0;
        for(int i=0; i<n; i++){
            if(A[i]<L) A[i] = 0;
            else if(A[i]>R) A[i] = 2;
            else A[i] = 1;
        }
        int res = 0;
        int i=0;
        while(i<n){
            if(A[i]==2){
                i++;
                continue;
            }
            int count = 0; int countz = 0;
            while(i<n && A[i]!=2){
                count++;
                if(A[i]==0){
                    countz++;
                }
                else countz = 0;
                res += count - countz;
                i++;
            }
        }
        return res;
    }
};