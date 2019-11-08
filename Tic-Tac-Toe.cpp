class TicTacToe {
public:
    /** Initialize your data structure here. */
    int r[10000] = {0};
    int c[10000] = {0};
    int d = 0,ad = 0,size;
    TicTacToe(int n) {
        size = n;
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        if(player == 1){
            r[row]--;
            c[col]--;
            if(row == col) d--;
            if(row + col == size-1)ad--;
        }
        else if(player == 2){
            r[row]++;
            c[col]++;
            if(row == col) d++;
            if(row + col == size-1)ad++;
        }
        if(r[row] == size || c[col] == size || d == size || ad == size){
            return 2;
        }
        if(r[row] == -size || c[col] == -size || d == -size || ad == -size){
            return 1;
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */