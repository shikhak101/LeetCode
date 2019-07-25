class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        pair<int, int> p[points.size()];
        for(int i=0; i< points.size(); i++)
        {
            int distance = (points[i][0]*points[i][0]) + (points[i][1]*points[i][1]);
            p[i].first=distance;
            p[i].second=i;
        }
        sort(p,p+points.size());
        for(int i=0; i<K; i++){
            result.push_back(points[p[i].second]);
        }
        return result;
    }
};