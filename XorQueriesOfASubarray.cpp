class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for(int i=0; i<queries.size(); i++) {
            int s = queries[i][0];
            int e = queries[i][1];
            int val = 0;
            for(int j = s; j<=e; j++) {
                val = val^arr[j];
            }
            res.push_back(val);
        }
        return res;
    }
};