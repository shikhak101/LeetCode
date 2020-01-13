class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        if(A.size() == 0) return 0;
        int res = 0;
        unordered_map<int,int> m;
        for(auto x:C) {
            for(auto y:D) {
                m[x+y]++;
            }
        }
        for(auto x:A) {
            for(auto y:B) {
                res = res + m[0-(x+y)];
            }
        }
        return res;
    }
};