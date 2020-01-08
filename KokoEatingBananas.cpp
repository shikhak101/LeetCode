class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int minb = 1; int maxb = INT_MIN;
        for(int i=0; i<piles.size(); i++) {
            maxb = max(piles[i],maxb);
        }
        int res = maxb;
        while(minb<=maxb) {
            int mid = minb + (maxb-minb)/2;
            int cH = 0;
            for(int i=0; i<piles.size(); i++) {
                double p = piles[i];
                double hours = p/mid;
                cH += ceil(hours);
            }
            if(cH>H) {
                minb = mid+1;
            }
            else {
                maxb = mid-1;
                res = min(res,mid);
            }
        }
        return res;
    }
};