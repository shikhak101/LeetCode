class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        string new_s="";
        int force[n] = {0};
        int f = 0;
        for(int i=0; i<n; i++) {
            if(dominoes[i] == 'R') f = n;
            else if(dominoes[i] == 'L') f = 0;
            else f = max(f-1,0);
            force[i] += f;
        }
        f = 0;
        for(int i=n-1; i>=0; i--) {
            if(dominoes[i] == 'R') f = 0;
            else if(dominoes[i] == 'L') f = n;
            else f = max(f-1,0);
            force[i] -= f;
        }
        for(int i=0; i<n; i++) {
            if(force[i] == 0) new_s += '.';
            else if(force[i] > 0) new_s += 'R';
            else if(force[i] < 0) new_s += 'L';
        }
        return new_s;
    }
};