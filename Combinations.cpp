class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        vector<int> eachres;
        backtrack(n,k,1,eachres);
        return res;
    }
    void backtrack(int n, int k, int first, vector<int> eachres) {
        if(eachres.size() == k) {
            res.push_back(eachres);
            return;
        }
        for(int i = first; i<n+1; i++) {
            eachres.push_back(i);
            backtrack(n,k,i+1,eachres);
            eachres.pop_back();
        }
        return;
    }
};