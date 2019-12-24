class Solution {
public:
    void backtrack(int sum,int v,int k, int n, vector<vector<int>>& res, vector<int> curr) {
        if(curr.size()==k && sum==n) {
            res.push_back(curr);
            return;
        }
        for(int i=v;i<10; i++) {
            curr.push_back(i);
            backtrack(sum+i,i+1,k,n,res,curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        if(n==0) return res;
        vector<int> curr;
        backtrack(0,1,k,n,res,curr);
        return res;
    }
};