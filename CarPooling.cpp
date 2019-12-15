bool comp(const vector<int> & a, const vector<int> & b) {
    return a[1]<b[1];
}
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(),trips.end(),comp);
        int curr = 0;
        queue<int> q1;
        queue<int> q2;
        for(int i=0; i<trips.size(); i++) {
            if(!q1.empty()){
                while(!q1.empty()){
                    if(trips[i][1]>=trips[q1.front()][2])
                        curr -= trips[q1.front()][0];
                    else q2.push(q1.front());
                    q1.pop();
                }
                while(!q2.empty()) {
                    q1.push(q2.front()); q2.pop();
                }
            }
            q1.push(i);
            curr += trips[i][0];
            if(curr>capacity) return false;
        }
        return true;
    }
};