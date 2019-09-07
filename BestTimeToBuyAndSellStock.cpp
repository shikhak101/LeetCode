class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxdiff = 0;
            if(prices.size()>1) {
            int maxprice = prices[prices.size()-1];

            for(int i = prices.size()-1; i>=0; i--)
            {
                if(maxprice-prices[i] > maxdiff) maxdiff = maxprice - prices[i];
                if(maxprice < prices[i]) maxprice = prices[i];
            }
        }
        return maxdiff;
    }
};