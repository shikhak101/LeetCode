class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        int m = flights.size();
        if(m==0) return 0;
        vector<int> stops(n,INT_MAX);
        vector<vector<int>> adjmat(n,vector<int>(n,INT_MAX));
        for(auto x:flights){
            adjmat[x[0]][x[1]] = x[2];
        }
        queue<int> q;
        vector<int> cost(n,INT_MAX);
        q.push(src);
        cost[src] = 0;
        stops[src] = 0;
        int minres = INT_MAX;
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            int ck = stops[curr];
            int c_cost = cost[curr];
            if(curr == dst){
                minres = min(minres,c_cost);
            }
            if(ck > K) continue;
            for(int i=curr+1; i<n; i++) {
                if(adjmat[curr][i] == INT_MAX) continue;
                if(i != dst && ck == K) continue;
                if(cost[i] > c_cost + adjmat[curr][i]) {
                    q.push(i);
                    stops[i] = ck+1;
                    cost[i] = c_cost + adjmat[curr][i];
                }
            }
            for(int i=0; i<curr; i++) {
                if(adjmat[curr][i] == INT_MAX) continue;
                if(i != dst && ck == K) continue;
                if(cost[i] > c_cost + adjmat[curr][i]) {
                    q.push(i);
                    stops[i] = ck+1;
                    cost[i] = c_cost + adjmat[curr][i];
                }
            }
        }
        if(minres == INT_MAX) minres = -1;
        return minres;
    }
};