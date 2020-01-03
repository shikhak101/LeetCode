class Solution {
public:
    int res;
    int backtrack(vector<vector<int>>& m, vector<bool>& vis, int curr) {
        if(res == m.size()-1) return res;
        vis[curr] = true;
        int m1 = 0; int m2 = 0;
        for(int i=0; i<m[curr].size(); i++) {
            if(vis[m[curr][i]] == true) continue;
            int n = backtrack(m,vis,m[curr][i]);
            if(n>m1){
                m2 = m1;
                m1 = n;
            }
            else if(n>m2){
                m2 = n;
            }
        }
        res = max(res,m1+m2+1);
        return m1+1;
    }
    int treeDiameter(vector<vector<int>>& edges) {
        int n = edges.size();
        if(n==0) return 0;
        vector<vector<int>> m(n+1,vector<int>());
        for(int i=0; i<n; i++) {
            m[edges[i][0]].push_back(edges[i][1]);
            m[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(n+1,false);
        res = 0;
        backtrack(m,vis,0);
        return res-1;
    }
};