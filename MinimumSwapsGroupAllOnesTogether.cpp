class Solution {
public:
    int minSwaps(vector<int>& data) {
        int ones = 0; int start = 0;
        for(int i=0; i<data.size(); i++) {
            if(data[i] == 1) ones++;
        }
        if(ones<=1) return 0;
        int res = ones;
        int zeroes = 0;
        for(int i=0;i<data.size(); i++) {
            if(data[i] == 0) zeroes++;
            if(i-start+1 == ones) {
                res = min(res,zeroes);
                if(data[start]==0) zeroes--;
                start++;
            }
        }
        return res;
    }
};