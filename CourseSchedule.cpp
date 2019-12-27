class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,set<int>> m;
        for(int i=0; i<prerequisites.size(); i++) {
            if(m.find(prerequisites[i][0]) == m.end()) {
                set<int> t;
                t.insert(prerequisites[i][1]);
                m.insert({prerequisites[i][0],t});
            }
            else {
                m[prerequisites[i][0]].insert(prerequisites[i][1]);
            }
        }
        set<int> res;
        queue<int> q;
        for(int i=0; i<numCourses; i++) {
            if(m.find(i) == m.end()) {
                q.push(i);
                res.insert(i);
            }
        }
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            for(auto x:m) {
                if(x.second.find(curr) != x.second.end()){
                    x.second.erase(curr);
                    m[x.first] = x.second;
                }
                if(x.second.size() == 0 && res.find(x.first) == res.end()) {
                    res.insert(x.first);
                    q.push(x.first);
                }
            }
        }
        if(res.size() == numCourses) return true;
        return false;
    }
};