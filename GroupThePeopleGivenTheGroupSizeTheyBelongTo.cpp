class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& g) {
        map<int,vector<int>> m;
        for(int i=0; i<g.size(); i++) {
            if(m.find(g[i])==m.end()) {
                vector<int> t;
                t.push_back(i);
                m.insert({g[i],t});
            }
            else {
                m[g[i]].push_back(i);
            }
        }
        vector<vector<int>> res;
        for(auto x:m) {
            int itr = x.second.size()/x.first;
            int k = 0;
            for(int i=0; i<itr; i++) {
                vector<int> t;
                for(int j = 0; j<x.first; j++) {
                    t.push_back(x.second[k++]);
                }
                res.push_back(t);
            }
        }
        return res;
    }
};