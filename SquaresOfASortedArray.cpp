class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i;
        int n = A.size();
        int j = 0;
        while(j<n && A[j]<0)
        {
            j++;
        }
        i = j-1;
        vector<int> result;
        while(i>=0 && j<n) {
            if(A[i]*A[i] < A[j]*A[j]) {
                result.push_back(A[i]*A[i]);
                i--;
            }
            else {
                result.push_back(A[j]*A[j]);
                j++;
            }
        }
        while(i>=0) {
            result.push_back(A[i]*A[i]);
            i--;
        }
        while(j<n) {
            result.push_back(A[j]*A[j]);
            j++;
        }
        return result;
    }
};