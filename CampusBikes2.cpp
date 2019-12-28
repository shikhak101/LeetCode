class Solution {
public:
    int res = INT_MAX;
    int n; int m;
    vector<vector<int>> ws;
    vector<vector<int>> bs;
    void findmindist(vector<bool>& vis,int a,int curr) {
        if(a == n) {
            res = min(res,curr);
            return;
        }
        for(int j=0; j<m; j++) {
            if(vis[j] == false) {
                vis[j] = true;
                int dist = abs(ws[a][0]-bs[j][0]) + abs(ws[a][1]-bs[j][1]);
                if(curr+dist < res)
                    findmindist(vis,a+1,curr+dist);
                vis[j] = false;
            }
        }
    }
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        n = workers.size();
        m = bikes.size();
        vector<bool> vis(m,false);
        ws = move(workers);
        bs = move(bikes);
        findmindist(vis,0,0);
        return res;
    }
};