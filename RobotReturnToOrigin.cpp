class Solution {
public:
    bool judgeCircle(string moves) {
        int v = 0, h = 0;
        for(int i=0; i<moves.length(); i++) {
            if(moves[i] == 'U') ++v;
            else if(moves[i] == 'D') --v;
            else if(moves[i] == 'L') --h;
            else if(moves[i] == 'R') ++h;
        }
        if(v == 0 && h == 0) return true;
        return false;
    }
};