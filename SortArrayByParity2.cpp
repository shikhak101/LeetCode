class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i=0; int j=1;
        while(i<A.size() && j<A.size()) {
            if(A[i]%2 == 1 && A[j]%2 == 0) {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
                i+=2; j+=2;
            }
            else if(A[i]%2 == 0 && A[j]%2 == 0) {
                i+=2;
            }
            else if(A[i]%2 == 1 && A[j]%2 == 1) {
                j+=2;
            }
            else if(A[i]%2 == 0 && A[j]%2 == 1) {
                i+=2; j+=2;
            }
        }
        return A;
    }
};