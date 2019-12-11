class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int,vector<int>> m;
        for(int i=0;i<ppid.size(); i++) {
            m[ppid[i]].push_back(pid[i]);
        }
        vector<int> res;
        stack<int> st;
        st.push(kill);
        while(!st.empty()) {
            int val = st.top();
            res.push_back(val);
            st.pop();
            for(int i=0; i<m[val].size(); i++) {
                st.push(m[val][i]);
            }
        }
        return res;
    }
};