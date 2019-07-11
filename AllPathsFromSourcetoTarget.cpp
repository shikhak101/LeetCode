class Solution {
public:
    vector<vector<int>> allpaths;
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path;
        if (graph.size() == 0) return allpaths;
        path.push_back(0);
        solution(graph, 0, path);
        return allpaths;
    }
    void solution(vector<vector<int>>& graph, int t, vector<int> path) {
        for(int i=0; i<graph[t].size(); i++) {
            if(graph[t][i] == graph.size()-1) {
                path.push_back(graph[t][i]);
                allpaths.push_back(path);
            }
            else
                path.push_back(graph[t][i]);
            solution(graph, graph[t][i],path);
            path.pop_back();
        }
        path.pop_back();
    }
};