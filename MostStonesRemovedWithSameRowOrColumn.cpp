class DSU {
public:
    vector<int> parent;
    DSU(int n) {
        for(int i=0; i<n; i++) {
            parent.push_back(i);
        }
    }
    int find(int x) {
        if(parent[x]!=x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void union1(int x, int y) {
        parent[find(x)] = find(y);
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        DSU dsu(20000);
        
        for(int i=0; i<n; i++) {
            dsu.union1(stones[i][0],stones[i][1]+10000);
        }
        set<int> visited;
        for(int i=0; i<n; i++) {
            visited.insert(dsu.find(stones[i][0]));
        }
        return n-visited.size();
    }
};
