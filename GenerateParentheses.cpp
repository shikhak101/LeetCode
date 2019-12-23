#include<algorithm>
class Solution {
public:
    void backtrack(vector<string>& res, string curr, int i, int j, int n) {
        if(curr.length() == n*2) {
            res.push_back(curr);
            return;
        }
        if(i<n) {
            backtrack(res,curr+"(",i+1,j,n);
        }
        if(j<i) {
            backtrack(res,curr+")",i,j+1,n);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n == 0) {
            res.push_back("");
        }
        else {
            backtrack(res,"",0,0,n);
        }
        return res;
    }
};