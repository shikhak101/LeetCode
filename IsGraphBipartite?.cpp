class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        for(int i=0; i<graph.size(); i++) {
            if(color[i] == -1) {
                stack<int> st;
                st.push(i);
                color[i] = 0;
                while(!st.empty()) {
                    int curr = st.top();
                    st.pop();
                    for(int j=0; j<graph[curr].size(); j++) {
                        int node = graph[curr][j];
                        if(color[node] == -1) {
                            color[node] = color[curr] ^ 1;
                            st.push(node);
                        }
                        else if (color[node] == color[curr]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};