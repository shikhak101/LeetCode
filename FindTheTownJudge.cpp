class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> trustcount(N+1,0);
        vector<int> visited(N+1,0);
        for(int i = 0; i<trust.size(); i++) {
            visited[trust[i][0]] ++;
            trustcount[trust[i][1]]++;
        }
        if(find(visited.begin()+1,visited.end(),0) == visited.end()) return -1;
        for(int i=1; i<visited.size(); i++)
            if(visited[i] == 0 && trustcount[i] == N-1) return i;
        
        return -1;
    }
};