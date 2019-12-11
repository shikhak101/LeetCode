class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int N) {
        int n = picture.size();
        if(n==0) return 0;
        int m = picture[0].size();
        vector<int> r(n,0);
        vector<string> rows;
        vector<int> c(m,0);
        vector<pair<int,int>> blks;
        for(int i=0; i<n; i++) {
            string w = "";
            for(int j=0; j<m; j++) {
                w += picture[i][j];
                if(picture[i][j]=='B') {
                    r[i]++;
                    c[j]++;
                    blks.push_back({i,j});
                }
            }
            rows.push_back(w);
        }
        int res = 0;
        for(auto b:blks) {
            if(r[b.first]==N && c[b.second]==N) {
                int i=0;
                for(i=0; i<n; i++) {
                    if(picture[i][b.second] == 'B' && i!=b.first) {
                        if(rows[i] != rows[b.first])
                            break;
                    }
                }
                if(i==n) res++;
            }
        }
        return res;
    }
};