class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        vector<pair<int,int>> dirs={{-2,-1},{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},                                            {-1,-2}};
        double res = 0;
        vector<vector<double>> m(N,vector<double>(N,0));
        m[r][c] = 1;
        while(K>0) {
            K--;
            vector<vector<double>> temp(N,vector<double>(N,0));
            for(int i=0; i<N; i++) {
                for(int j=0;j<N; j++) {
                    for(int k=0; k<8; k++) {
                        int x = i+dirs[k].first;
                        int y = j+dirs[k].second;
                        if(x>=0 && y>=0 && x<N && y<N) {
                            temp[x][y] += m[i][j]/8.0;
                        }
                    }
                }
            }
            m = move(temp);
        }
        for(int i=0; i<N; i++) {
            for(int j=0; j<N; j++) {
                res += m[i][j];
            }
        }
        return res;
    }
};