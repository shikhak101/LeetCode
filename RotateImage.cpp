class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int start = 0;
        int end = matrix.size()-1;
        int n = matrix.size();
        for(int i = 0; i<n/2; i++){
            for(int j=start; j<end; j++){
                int x = i;
                int y = j;
                int c = 4;
                int prev = matrix[x][y];
                while(c-- > 0) {
                    int curr = matrix[y][n-1-x];
                    matrix[y][n-1-x] = prev;
                    prev = curr;
                    int t = n-1-x;
                    x = y;
                    y = t;
                }
            }
            start++;
            end--;
        }
    }
};