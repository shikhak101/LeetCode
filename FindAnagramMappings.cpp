class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        map<int,vector<int>> m;
        for(int i=0; i<B.size(); i++) {
            int x = B[i];
            if(m.find(x) == m.end()) {
                vector<int> t;
                t.push_back(i);
                m.insert({x,t});
            }
            else m[x].push_back(i);
        }
        vector<int> res;
        for(int i=0; i<A.size(); i++) {
            vector<int> t = m[A[i]];
            res.push_back(t[t.size()-1]);
            m[A[i]].pop_back();
        }
        return res;
    }
};