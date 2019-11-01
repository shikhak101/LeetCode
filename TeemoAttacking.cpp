class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int k) {
        int sum = 0; 
        int currtime = -1;
        for(auto x:timeSeries){
            if(currtime<x){
                sum += k;
                currtime = x-1+k;
            }
            else {
                if(x-1+k>currtime) {
                    sum = sum + (x-1+k)-currtime;
                    currtime = x-1+k;
                }
            }
        }
        return sum;
    }
};