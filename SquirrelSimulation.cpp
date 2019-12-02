class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int maxdist = INT_MIN;
        int distfromtree = 0;
        for(int i=0; i<nuts.size(); i++) {
            int dists = abs(nuts[i][0]-squirrel[0]) + abs(nuts[i][1]-squirrel[1]);
            int distt = abs(nuts[i][0]-tree[0]) + abs(nuts[i][1]-tree[1]);
            maxdist = max(maxdist,distt-dists);
            distfromtree += 2*(abs(nuts[i][0]-tree[0]) + abs(nuts[i][1]-tree[1]));
        }
        distfromtree -= maxdist;
        return distfromtree;
    }
};