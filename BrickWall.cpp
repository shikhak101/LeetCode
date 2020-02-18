class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size();
        map<int,int> m;
        for(int i=0; i<n; i++){
            int sum = 0;
            for(int j=0; j<wall[i].size()-1; j++){
                sum+=wall[i][j];
                m[sum]++;
            }
        }
        int res=n;
        for(auto x:m){
            res = min(res,n-x.second);
        }
        return res;
    }
};