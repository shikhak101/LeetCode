class Solution {
public:
    vector<int> parent;
    int find(int x) {
        if(parent[x]==x) {
            return x;
        }
        return find(parent[x]);
    }
    void union1(int x, int y) {
        parent[find(x)] = parent[find(y)];
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1) return -1;
        vector<int> p(n,-1);
        int res = 0;
        parent = move(p);
        for(int i=0; i<n; i++) {
            parent[i]= i;
        }
        int count = 0;
        vector<bool> vis(n,false);
        for(int i=0; i<connections.size(); i++) {
            int x = connections[i][0];
            int y = connections[i][1];
            if(vis[x]==false && vis[y]==false) {
                count++;
            }
            else {
                vis[x] = true;
                vis[y] = true;
            }
            union1(x,y);
        }
        for(int i=0; i<n; i++) {
            if(parent[i]==i) res++;
        }
        return res-1;
    }
};