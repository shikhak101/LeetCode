class Solution {
public:
    vector<int> parent;
    int root(int i){
        while(parent[i]!=i){
            i = parent[i];
        }
        return i;
    }
    bool find(int x, int y){
        int px = root(x);
        int py = root(y);
        if(px==py) return true;
        return false;
    }
    void merge(int x, int y){
        int px = root(x);
        int py = root(y);
        if(px==py) return;
        parent[px] = py; 
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        int n1 = edges.size();
        for(int i=0; i<n; i++) parent.push_back(i);
        for(int i=0; i<n1; i++){
            int x = edges[i][0];
            int y = edges[i][1];
            merge(x,y);
        }
        int res = 0;
        for(int x = 0; x<n; x++){
            if(parent[x]==x) res++;
        }
        return res;
    }
};