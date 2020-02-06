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
    void merge(int x,int y){
        int px = root(x);
        int py = root(y);
        if(px==py) return ;
        parent[root(x)] = root(y);
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int> res;
        if(edges.size()==0) return res;
        parent.push_back(0);
        for(int i=0; i<edges.size(); i++){
            parent.push_back(i+1);
        }
        for(int i=0; i<edges.size(); i++){
            int x = edges[i][0];
            int y = edges[i][1];
            if(find(x,y)){
                res.push_back(x);
                res.push_back(y);
                return res;
            }
            else{
                merge(x,y);
            }
        }
        return res;
    }
};