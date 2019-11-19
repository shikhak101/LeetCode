class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        for(int i=0; i<=num; i++){
            int count = 0;
            int n = i;
            for(int j=0; j<32; j++){
                count += n & 1;
                n = n>>1;
            }
            res.push_back(count);
        }
        return res;
    }
};