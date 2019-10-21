class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i=0; i<matrix.size();i++) {
            int k = i; 
            int j = 0;
            int val = matrix[k][j];
            while(k<matrix.size() && j<matrix[0].size()) {
                if(matrix[k][j] != val){
                    return false;
                } k++; j++;
            }
        }
        for(int j = 1; j< matrix[0].size(); j++) {
            int k = j;
            int i = 0;
            int val = matrix[i][k];
            while(k<matrix[0].size() && i<matrix.size()) {
                if(val != matrix[i][k]){
                    return false;
                } k++; i++;
            }
        }
        return true;
    }
};