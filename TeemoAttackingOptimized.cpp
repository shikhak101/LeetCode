class Solution {
public:
    int findPoisonedDuration(vector<int>& timeseries, int k) {
        int sum = 0; 
        if(timeseries.size()==0) return 0;
        for(int i = 0; i<timeseries.size()-1; i++) {
            sum += min(timeseries[i+1]-timeseries[i],k);
        }
        return sum+k;
    }
};