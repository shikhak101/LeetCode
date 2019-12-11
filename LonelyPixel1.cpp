class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int n = picture.size();
        if(n==0) return 0;
        int m = picture[0].size();
        int res = 0;
        vector<int> row(n,0);
        vector<int> col(m,0);
        vector<pair<int,int>> blacks;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(picture[i][j]=='W') continue;
                row[i]++;
                col[j]++;
                blacks.push_back({i,j});
            }
        }
        for(auto b:blacks){
            if(row[b.first] == 1 && col[b.second]==1) res++;
        }
        return res;
    }
};