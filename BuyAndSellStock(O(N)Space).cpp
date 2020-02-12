class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0;
        int n = prices.size();
        if(n==0) return 0;
        int val = 0;
        vector<int> maxv(n,0);
        for(int i=n-1; i>=0; i--){
            if(val<prices[i]){
                maxv[i] = prices[i];
                val = prices[i];
            }
            else {
                maxv[i] = val;
            }
        }
        for(int i=0; i<n; i++){
            if(maxv[i]>prices[i]){
                res = max(res,maxv[i]-prices[i]);
            }
        }
        return res;
    }
};