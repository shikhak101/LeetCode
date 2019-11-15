class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        for(int i=1; i<costs.size(); i++) {
            int j = i-1;
            int item1 = costs[i][0];
            int item2 = costs[i][1];
            while(j>=0 && (item1-item2)<(costs[j][0]-costs[j][1])) {
                costs[j+1][0] = costs[j][0];
                costs[j+1][1] = costs[j][1];
                j--;
            }
            costs[j+1][0] = item1;
            costs[j+1][1] = item2;
        }
        int res = 0;
        for(int i=0; i<costs.size(); i++){
            if(i<costs.size()/2) res += costs[i][0];
            else res += costs[i][1];
        }
        return res;
    }
};