class Solution {
public:
    void update(vector<vector<char>>& board, int x, int y) {
        if(board[x][y] !='E') return;
        int dx[8] = {0,1,-1,0,-1,1,1,-1};
        int dy[8] = {1,0,0,-1,1,1,-1,-1};
        int count = 0;
        for(int i = 0; i<8; i++) {
            int tx = x+dx[i];
            int ty = y+dy[i];
            if(tx<0 || ty<0 || tx>board.size()-1 || ty>board[0].size()-1) continue;
            if(board[tx][ty] == 'M') count++;
        }
        if(count>0) board[x][y] = count + '0';
        else {
            board[x][y] = 'B';
            for(int i = 0; i<8; i++) {
                int tx = x+dx[i];
                int ty = y+dy[i];
                if(tx<0 || ty<0 || tx>board.size()-1 || ty>board[0].size()-1) continue;
                if(board[tx][ty] == 'E') 
                    update(board,tx,ty);
            }
        }
    }
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int x = click[0];
        int y = click[1];
        if(board[x][y] == 'M') {
            board[x][y] = 'X';
            return board;
        }
        update(board,x,y);
        return board;
    }
};