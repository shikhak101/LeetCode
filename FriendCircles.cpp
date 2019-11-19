class UF{
public:
    vector<int> parent;
    UF(int n){
        for(int i=0; i<n; i++){
            parent.push_back(-1);
        }
    }
    int find(int x){
        if(parent[x] == -1) return x;
        return find(parent[x]);
    }
    void union1(int x, int y) {
        int xset = find(x);
        int yset = find(y);
        if (xset != yset)
            parent[xset] = yset;
    }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        UF* uf = new UF(M.size());
        for(int i=0; i<M.size(); i++) {
            for(int j=0; j<M.size(); j++){
                if(M[i][j] == 1 && i!=j) {
                    uf->union1(i,j);
                } 
            }
        }
        int res = 0;
        for(int i=0; i<uf->parent.size(); i++) {
            if(uf->parent[i] == -1) res++;
        }
        return res;
    }
};