class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        vector<int> res;
        int sum = 0;
        for(int j=0; j<A.size(); j++) {
            if(A[j]%2 == 0) sum+=A[j];
        }
        for(int i=0; i<queries.size(); i++) {
            int val = queries[i][0];
            int idx = queries[i][1];
            if(abs(A[idx]%2)==0 && abs(val%2)==0) sum += val;
            else if(abs(A[idx]%2) == 1 && abs(val%2) == 1) sum += A[idx] + val;
            else if(abs(A[idx]%2) == 0 && abs(val%2) == 1) sum -= A[idx];
            A[idx] += val;
            res.push_back(sum);
        }
        return res;
    }
};