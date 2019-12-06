class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
         vector<int> res;
        if(matrix.size()==0) return res;
        int r = matrix.size();
        int c = matrix[0].size();
       
        map<int,vector<int>> m;
        for(int i=0; i<r; i++) {
            for(int j=0; j<c; j++){
                if(m.find(i+j) == m.end()) {
                    vector<int> t;
                    t.push_back(matrix[i][j]);
                    m.insert({i+j,t});
                }
                else{
                    m[i+j].push_back(matrix[i][j]);
                }
            }
        }
        int counter = 0;
        for(auto x:m){
            if(counter == 1){
                for(int i=0; i<x.second.size(); i++) {
                    res.push_back(x.second[i]);
                }
                counter = 0;
            }
            else {
                for(int i=x.second.size()-1; i>=0; i--) {
                    res.push_back(x.second[i]);
                }
                counter = 1;
            }
            
        }
        return res;
    }
};