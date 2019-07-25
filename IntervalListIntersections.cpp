class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int>> result;
        for(int j = 0; j<B.size(); j++) {
            for(int i = 0; i<A.size(); i++)
            {
                vector<int> v;
                if(A[i][0]>B[j][1]) break;
                if(A[i][1]<B[j][0]) continue;
                if(A[i][0] < B[j][0]) v.push_back(B[j][0]);
                else v.push_back(A[i][0]);
                if(A[i][1] < B[j][1]) v.push_back(A[i][1]);
                else v.push_back(B[j][1]);
                result.push_back(v);
            }
        }
        return result;
    }
};