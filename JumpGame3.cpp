class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        queue<int> q;
        vector<int> vis(arr.size(),false);
        q.push(start);
        vis[start] = true;
        while(!q.empty()) {
            int idx = q.front();
            q.pop();
            if(arr[idx] == 0) return true;
            int back = idx-arr[idx];
            int forw = idx+arr[idx];
            if(back>=0 && back<arr.size() && vis[back] == false) {
                if(arr[back]==0) return true;
                q.push(back);
                vis[back] = true;
            }
            if(forw>=0 && forw<arr.size() && vis[forw] == false) {
                if(arr[forw]==0) return true;
                q.push(forw);
                vis[forw] = true;
            }
        }
        return false;
    }
};