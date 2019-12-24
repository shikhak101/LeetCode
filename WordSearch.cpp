class Solution {
public:
    vector<pair<int,int>> dirs = {{1,0},{0,1},{-1,0},{0,-1}};
    bool findword(vector<vector<char>> board, string word, int n, int m, int a, int b, string curr, vector<vector<bool>>vis, int pos) {
        if(curr == word) {
            return true;
        }
        for(int i=0; i<4; i++) {
            int x = a+dirs[i].first;
            int y = b+dirs[i].second;
            if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==false && board[x][y]==word[pos]) {
                vis[x][y] = true;
                bool r = findword(board,word,n,m,x,y,curr+word[pos],vis,pos+1);
                if(r == true) return true;
                vis[x][y]=false;                
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        if(word.length()==0) return true;
        if(n==0) return false;
        int m=board[0].size();
        if(word.size()>n*m) return false;
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n; i++) {
            for(int j=0; j<m; j++) {
                if(board[i][j]!=word[0]) continue;
                string s="";
                s+=word[0];
                vis[i][j]=true;
                bool res = findword(board,word,n,m,i,j,s,vis,1);
                vis[i][j]=false;
                if(res == true) return true;
            }
        }
        return false;
    }
};