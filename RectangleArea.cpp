class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int commonArea = 0;
        int x1 = max(A,E);
        int x2 = min(C,G);
        int y1 = max(B,F);
        int y2 = min(D,H);
        if(x1<x2 && y1<y2)
            commonArea = (x2-x1)*(y2-y1);
        int rec1 = (C-A)*(D-B);
        int rec2 = (G-E)*(H-F);
        rec1 -= commonArea;
        return abs(rec1+rec2);
    }
};