class Solution {
public:
    bool leadsToDestination(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> visited(n,0);
        map<int,vector<int>> m;
        for(auto x:edges){
            if(m.find(x[0]) == m.end()){
                vector<int> t;
                t.push_back(x[1]);
                m.insert({x[0],t});
            }
            else {
                m[x[0]].push_back(x[1]);
            }
        }
        queue<int> q;
        q.push(source);
        visited[source] = 1;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            visited[node] = 2;
            if(m.find(node)==m.end() && node != destination) {
                return false;
            }
            for(int i=0; i<m[node].size(); i++) {
                if(visited[m[node][i]] == 0) {
                    q.push(m[node][i]);
                    visited[m[node][i]] = 1;
                }
                else if(visited[m[node][i]] == 2) {
                    return false;
                }
            }
        }
        return true;
    }
};