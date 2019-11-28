class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> mincoins(amount+1,INT_MAX-1);
        mincoins[0] = 0;
        for(int i=1; i<=amount; i++) {
            for(auto c:coins) {
                if(c<=i){
                    mincoins[i] = min(mincoins[i],mincoins[i-c]+1);
                }
            }
        }
        return mincoins[amount]>amount ? -1 : mincoins[amount];
    }
};