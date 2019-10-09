class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        return solution(matrix,target,0,0,matrix.size(),matrix[0].size());
    }
    bool solution(vector<vector<int>>& matrix, int target, int i, int j,int m, int n) {
        int x = -1;
        int y = -1;
        while(i<m && j<n) {
            int val = matrix[i][j];
            if(val == target) return true;
            if(val<target) {
                i++; j++; continue;
            }
            else if(val > target) {
                x = i; 
                y = j;
                break;
            }
        }
        if(x == -1) {
            if(i==m && j==n) return false;
            if(i<m) 
                return solution(matrix,target,i,0,m,n);
            if(j<n)
                return solution(matrix,target,0,j,m,n);
        }
        else{
            if(bsx(0,y,matrix,target,x)) return true;
            if(bsy(0,x,matrix,target,y)) return true;
            return solution(matrix,target,i+1,j+1,m,n);
            return false;
        }
        return false;
    }
    bool bsx(int low, int high, vector<vector<int>>& matrix, int target, int x) {
        if(low==high && matrix[x][low]==target) return true;
        if(low > high) return false;
        int mid = (low+high)/2;
        int val = matrix[x][mid];
        if(val == target) return true;
        if(val > target) {
            return bsx(low,mid-1,matrix,target,x);
        }
        else return bsx(mid+1,high,matrix,target,x);
        return false;
    }
    bool bsy(int low, int high, vector<vector<int>>& matrix, int target, int y) {
        if(low==high && matrix[low][y]==target) return true;
        if(low > high) return false;
        int mid = (low+high)/2;
        int val = matrix[mid][y];
        if(val == target) return true;
        if(val > target) {
            return bsy(low,mid-1,matrix,target,y);
        }
        else return bsy(mid+1,high,matrix,target,y);
        return false;
    }
};