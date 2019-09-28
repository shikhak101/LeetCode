class Solution {
public:
    vector<vector<int>> res;
    void solution(vector<int> v, vector<int> currres,int c, int sum) {
        if(sum == 0) {
            res.push_back(currres);
            return;
        }
        for(int i=c; i<v.size(); i++){
            if(sum-v[i] >= 0) {
                currres.push_back(v[i]);
                solution(v,currres,i,sum-v[i]);
                currres.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> currres;
        if(candidates.size()>0) solution(candidates,currres,0,target);
        return res;
    }
};