class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        multimap<int,pair<int,int>> m;
        for(int i=0; i<R; i++) {
            for(int j=0; j<C; j++) {
                int dist = abs(r0-i) + abs(c0-j);
                pair<int,int> p;
                p = make_pair(i,j);
                m.insert(make_pair(dist,p));
            }
        }
        vector<vector<int>> res;
        for(auto x:m) {
            vector<int> t(2);
            pair<int,int> p = x.second;
            t[0] = p.first;
            t[1] = p.second;
            res.push_back(t);
        }
        return res;
    }
};