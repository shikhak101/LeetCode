class UF {
public:
    vector<int> parent;  
    UF(int n) {
        for(int i=0; i<n; i++){
            parent.push_back(i);
        }
    }
    int find(int x){
        if(parent[x]!=x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void union1(int x, int y){
        parent[find(x)] = find(y);
    }
};
class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        UF* uf = new UF(n*n*4);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++) {
                char c= grid[i][j];
                int root = 4*(i*n+j);
                if(c != '\\') {
                    uf->union1(root,root+1);
                    uf->union1(root+2,root+3);
                }
                if(c != '/') {
                    uf->union1(root,root+2);
                    uf->union1(root+1,root+3);
                }
                if(i+1<n) {
                    uf->union1(root+3,root+(4*n));
                }
                if(i-1>=0) {
                    uf->union1(root,(root-(4*n))+3);
                }
                if(j+1<n) {
                    uf->union1(root+2,(root+4)+1);
                }
                if(j-1>=0) {
                    uf->union1(root+1,(root-4)+2);
                }
            }
        }
        int res = 0;
        for(int i=0; i<n*n*4; i++){
            if(i == uf->find(i)) ++res;
        }
        return res;
    }
};