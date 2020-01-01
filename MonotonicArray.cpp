class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        int t = 0;
        for(int i=0; i<A.size()-1; i++) {
            if(A[i] == A[i+1]) continue;
            if(t==0) {
                if(A[i]<A[i+1]) t=1;
                else t = -1;
            }
            if(t==-1 && A[i]<A[i+1]) return false;
            if(t==1 && A[i]>A[i+1]) return false;
        }
        return true;
    }
};