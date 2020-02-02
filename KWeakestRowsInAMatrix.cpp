bool comp(pair<int,int> p1, pair<int,int> p2){
    if(p1.second==p2.second){
        return p1.first<p2.first;
    }
    return p1.second<p2.second;
}
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<int> res;
        int n = mat.size();
        if(n==0) return res;
        int m1 = mat[0].size();
        if(m1==0) return res;
        vector<pair<int,int>> m;
        for(int i=0; i<n; i++){
            int ones = 0;
            for(int j=0; j<m1; j++){
                if(mat[i][j]==1) ones++;
                else break;
            }
            m.push_back({i,ones});
        }
        sort(m.begin(),m.end(),comp);
        for(int i=0; i<k;i++){
            res.push_back(m[i].first);
        }
        return res;
    }
};