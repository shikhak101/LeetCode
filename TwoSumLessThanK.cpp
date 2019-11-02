class Solution {
public:
    int twoSumLessThanK(vector<int>& A, int K) {
        sort(A.begin(),A.end());
        int h = A.size()-1;
        while(h>=0 && A[h]>K) {
            h--;
        }
        int res = -1;
        int maxres = -1;
        for(int i = h; i>0; i--) {
            int j = i-1;
            while(j >=0 && A[i] + A[j] >= K) {
                j--;
            }
            if(j>=0 && A[i] + A[j] < K) {
                res = A[i] + A[j];
                maxres = max(res,maxres);
            }
        }
        return maxres;
    }
};