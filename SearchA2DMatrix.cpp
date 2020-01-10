class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        if(n==0) return false;
        int m = matrix[0].size();
        if(m==0) return false;
        int row = -1;
        int l = 0;
        int h = n-1;
        while(l<=h) {
            int mid = l+ (h-l)/2;
            if(target>=matrix[mid][0] && target<=matrix[mid][m-1]) {
                row = mid;
                break;
            }
            if(target<matrix[mid][0]) {
                h = mid-1;
            }
            else if(target>matrix[mid][m-1]) {
                l = mid+1;
            }
        }
        if(row == -1) return false;
        l = 0; h = m-1;
        while(l<=h) {
            int mid = l + (h-l)/2;
            if(target == matrix[row][mid]) return true;
            if(target<matrix[row][mid]) h = mid-1;
            else l = mid+1;
        }
        return false;
    }
};