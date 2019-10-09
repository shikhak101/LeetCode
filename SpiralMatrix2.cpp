class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int> (n));
        int low = 0; int high =n-1; int num = 1;
        while(low<high) {
            int i=low; int j;
            for(j=low; j<=high; j++) res[i][j] = num++;
            j--;
            for(i=low+1; i<=high; i++) res[i][j] = num++;
            i--;
            for(j=high-1; j>=low; j--) res[i][j] = num++;
            j++;
            for(i=high-1; i>low; i--) res[i][j] = num++;
            low++; high--;
        }
        if(low == high) res[low][high] = num;
        return res;
    }
};