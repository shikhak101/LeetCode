bool comp(const vector<int>& a, const vector<int>& b) {
    return a[0]<b[0];
}
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int res = 0;
        if(intervals.size()==0) return res;
        stack<pair<int,int>> st;
        sort(intervals.begin(),intervals.end(),comp);
        st.push({intervals[0][0],intervals[0][1]});
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=st.top().first && st.top().second>=intervals[i][1]) {
                continue;
            }
            while(!st.empty() && intervals[i][0]<=st.top().first && st.top().second<=intervals[i][1]){
                st.pop();
            }
            st.push({intervals[i][0],intervals[i][1]});
        }
        return st.size();
    }
};