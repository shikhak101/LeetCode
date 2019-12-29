class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int start = 0;
        int x = 0; int y = 0;
        int maxs = 0; int s = 0;
        for(int i=0; i<grumpy.size(); i++) {
            if(grumpy[i] == 1){
                s+=customers[i];
            }
            if(i-start+1 > X){
                if(grumpy[start] == 1)
                    s = s-customers[start];
                start++;
            }
            if(i-start+1 == X) {
                if(maxs<s) {
                    maxs = s;
                    x = start;
                    y = i;
                }
            }
        }
        int res = 0;
        for(int i=0; i<customers.size(); i++) {
            if(i<=y && i>=x) res+=customers[i];
            else if(grumpy[i] == 0) res+=customers[i];
        }
        return res;
    }
};