class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        set<pair<int,int>> s;
        for(auto x:points) {
            s.insert({x[0],x[1]});
        }
        int res = INT_MAX;
        for(auto i=s.begin(); i!=s.end(); i++) {
            auto l = i;
            l++;
            for(auto j= l; j!=s.end(); j++) {
                int x1= i->first;
                int y1 = i->second;
                int x2 = j->first;
                int y2 = j->second;
                if(x1 != x2 && y1 != y2)
                    if(s.find({x1,y2}) != s.end() && s.find({x2,y1}) != s.end())
                        res = min(res, abs(x2-x1)*abs(y2-y1));
            }
        }
        if(res == INT_MAX) return 0;
        return res;
    }
};