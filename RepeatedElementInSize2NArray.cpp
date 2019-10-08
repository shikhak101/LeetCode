class Solution {
public:
    int repeatedNTimes(vector<int>& A) {
        for(int i=1; i<A.size(); i++){
            if(A[i] == A[i-1]) return A[i];
            if(i>1 && A[i] == A[i-2]) return A[i];
            if(i>2 && A[i] == A[i-3]) return A[i];
            if(i>3 && A[i] == A[i-4]) return A[i];
        }
        return 0;
    }
};