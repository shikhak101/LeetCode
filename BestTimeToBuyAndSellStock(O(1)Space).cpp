class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int maxprofit = 0;
        int minval = INT_MAX;
        for(int i=0; i<n; i++){
            if(minval>prices[i]){
                minval = prices[i];
            }
            else if(prices[i]-minval>maxprofit){
                maxprofit = prices[i]-minval;
            }
        }
        return maxprofit;
    }
};