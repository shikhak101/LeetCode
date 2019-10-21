class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<vector<pair<int,int>>> sortv(2001);
        for(int i=0; i<workers.size(); i++) {
            for(int j=0; j<bikes.size(); j++) {
                int d = abs(workers[i][0] - bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                sortv[d].push_back({i,j});
            }
        }
        vector<int> res(workers.size(),-1);
        vector<int> visited(bikes.size(),0);
        for(int i=0; i<2001; i++) {
            for(int j = 0; j<sortv[i].size(); j++) {
                if(res[sortv[i][j].first] == -1 && visited[sortv[i][j].second] == 0) {
                    res[sortv[i][j].first] = sortv[i][j].second;
                    visited[sortv[i][j].second] = 1;
                }
            }
        }
        return res;
    }
};