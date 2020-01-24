class Solution {
public:
    int res = 0;
    void backtrack(int n, vector<int> v, vector<bool>& vis){
        if(v.size()==n+1){
            res++;
            return;
        }
        int c = v[v.size()-1];
        for(int i=1; i<=n; i++) {
            if(vis[i]==true) continue;
            if(i%v.size()==0 || v.size()%i==0){
                v.push_back(i);
                vis[i] = true;
                backtrack(n,v,vis);
                vis[i] = false;
                v.pop_back();
            }
        }
    }
    int countArrangement(int N) {
        vector<bool> vis(N+1,false);
        vector<int> v;
        v.push_back(0);
        vis[0] = true;
        backtrack(N,v,vis);
        return res;
    }
};