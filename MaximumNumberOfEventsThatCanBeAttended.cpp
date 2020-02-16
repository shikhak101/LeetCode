bool comp(vector<int>& v1, vector<int>& v2){
    return v1[1]<v2[1];
}
class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        int n = events.size();
        if(n<2) return n;
        sort(events.begin(),events.end(),comp);
        int minv = INT_MAX;
        int maxv = INT_MIN;
        for(int i=0; i<n; i++){
            minv = min(minv,events[i][0]);
            maxv = max(maxv,events[i][1]);
        }
        int res = 0;
        vector<int> v(maxv+1,0);
        for(int i=0; i<n; i++){
            int ss = events[i][0];
            int e = events[i][1];
            for(int j = ss; j<=e; j++){
                if(v[j]==0){
                    res++;
                    v[j]=1;
                    break;
                }
            }
        }
        return res;
    }
};