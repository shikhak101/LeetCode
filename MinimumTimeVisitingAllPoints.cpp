class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int res = 0;
        int x1 = points[0][0];
        int y1 = points[0][1];
        for(int i=1; i<points.size(); i++) {
            int x2 = points[i][0];
            int y2 = points[i][1];
            int diff1 = abs(x2-x1);
            int diff2 = abs(y2-y1);
            if(diff1>diff2) {
                res+=diff2;
                y1 = y2;
                if(x2<x1)
                    x1 -= diff2;
                else x1 += diff2;
            }
            else if(diff1<diff2) {
                res+=diff1;
                x1 = x2;
                if(y2<y1)
                    y1 -= diff1;
                else y1 += diff1;
            }
            else if(diff1 == diff2) {
                x1 = x2;
                y1 = y2; 
                res += diff1;
                continue;
            }
            if(x1!=x2) {
                res+=abs(x2-x1);
                x1 = x2;
            }
            else if(y1!=y2){
                res+=abs(y2-y1);
                y1=y2;
            }
        }
        return res;
    }
};