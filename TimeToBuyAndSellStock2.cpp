class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        int res = 0;
        int i = 0;
        while(i<n){
            while(i<n-1 && prices[i+1]<=prices[i]) i++;
            int j = i+1;
            while(j<n && prices[j]<=prices[i]) j++;
            if(j==n) i++;
            else {
                res += prices[j]-prices[i];
                i = j;
            }
        }
        return res;
    }
};