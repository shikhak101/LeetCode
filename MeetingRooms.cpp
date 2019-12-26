bool comp(vector<int> const & v1, vector<int> const & v2) {
    return v1[1]<v2[1];
}
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        if(intervals.size()==0) return true;
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=1; i<intervals.size(); i++) {
            if(intervals[i][0]<intervals[i-1][1]) return false;
        }
        return true;
    }
};