
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        // vector<vector<int>> result;
        // pair<int, int> p[points.size()];
        // for(int i=0; i< points.size(); i++)
        // {
        //     int distance = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
        //     p[i].first=distance;
        //     p[i].second=i;
        // }
        // sort(p,p+points.size());
        // for(int i=0; i<K; i++){
        //     result.push_back(points[p[i].second]);
        // }
        // return result;
        vector<vector<int>> res;
        priority_queue<tuple<int,int,int>> pq;
        for(int i=0; i<points.size(); i++) {
            int dist = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            pq.emplace(dist,points[i][0],points[i][1]);
            if(pq.size() > K){
                pq.pop();
            }
        }
        while(!pq.empty()) {
            vector<int> t;
            auto [a,k,l] = pq.top();
            pq.pop();
            t.push_back(k);
            t.push_back(l);
            res.push_back(t);
        }
        return res;
    }
};