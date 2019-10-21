class Solution {
public:
    struct Dis {
        int d;
        int w; 
        int b;
        bool operator<(const Dis& rhs) const{
            if(rhs.d != d) return d>rhs.d;
            if(rhs.w != w) return w>rhs.w;
            return b>rhs.b;
        }
    };
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        priority_queue<Dis> pq;
        for(int i=0; i<workers.size(); i++) {
            for(int j=0; j<bikes.size(); j++) {
                int d = abs(workers[i][0]-bikes[j][0]) + abs(workers[i][1]-bikes[j][1]);
                pq.push({d,i,j});
            }
        }
        vector<int> res(workers.size(), -1); 
        vector<int> visited(bikes.size(), 0);
        while(!pq.empty()) {
            auto [d,i,j] = pq.top();
            pq.pop();
            if(res[i] == -1 && visited[j] == 0) {
                res[i] = j;
                visited[j] = 1;
            }
        }
        return res;
    }
};