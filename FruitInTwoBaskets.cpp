class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int f = tree[0];
        int s = -1;
        int cntf = 1;
        int cnts = 0;
        int res = 0;
        int ptr = 0;
        for(int i=1; i<tree.size(); i++) {
            int x = tree[i];
            
            if(x == f) cntf++;
            else if(x == s) cnts++;
            else if(s == -1) {
                s = x;
                cnts = 1;
            }
            else{
                res = max(res,cntf+cnts);
                f = tree[ptr];
                cntf = i-ptr;
                s = x;
                cnts = 1;
            }
            if(x!=tree[i-1]) ptr = i;
        }
        res = max(res , cntf+cnts);
        return res;
    }
};