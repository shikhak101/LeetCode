class Solution {
public:
    void backtrack(vector<int>& c,int pos, vector<int>& curv,vector<vector<int>>& ret,int t, int n) {
        if(t==0) {
            ret.push_back(curv);
            for(auto x:curv) cout<<x<<",";
            cout<<endl;
            return;
        }
        for(int i = pos; i<n; i++) {
            if(c[i]>t) return;
            if(i&&c[i]==c[i-1] && i>pos) continue;
            curv.push_back(c[i]);
            backtrack(c,i+1,curv,ret,t-c[i],n);
            curv.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ret;
        if(candidates.size() == 0) return ret;
        vector<int> curv;
        sort(candidates.begin(),candidates.end());
        for(auto x:candidates) cout<<x<<",";
            cout<<endl;
        backtrack(candidates,0,curv,ret,target,candidates.size());
        return ret;
    }
};