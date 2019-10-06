class Solution {
public:
    int numTilePossibilities(string tiles) {
        map<char,int> m;
        for(int i=0; i<tiles.size(); i++) {
            m[tiles[i]]++;
        }
        return permute(m,tiles.size());
    }
    int permute(map<char,int>& m, int n) {
        if(n == 0) return 0;
        int sum = 0;
        for(auto& x:m) {
            if(x.second > 0) {
                x.second--;
                sum += 1 + permute(m,n-1);
                x.second++;
            }
        }
        return sum;
    }
};