https://leetcode.com/problems/design-tic-tac-toe/?envType=company&envId=google&favoriteSlug=google-thirty-days

class TicTacToe {
public:
    vector<int>Row;
    vector<int>Col;
    int diag = 0;
    int antiDiag = 0;

    int size;

    TicTacToe(int n) {
        Row.resize(n, 0);
        Col.resize(n, 0);
        size = n;
    }

    
    int move(int row, int col, int player) {
        int curVal = (player == 1) ? 1 : -1;
        if(row+col == size-1) antiDiag += curVal; 
        if(row == col) diag += curVal; 
        Row[row] += curVal;
        Col[col] += curVal;

        if(abs(antiDiag) == size || abs(diag) == size || abs(Row[row]) == size || abs(Col[col]) == size) return player;
        else return 0;
    }
};