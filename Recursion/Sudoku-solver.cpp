https://leetcode.com/problems/sudoku-solver/description/

class Solution {
public:
    bool isValid(int row, int col, char c, vector<vector<char>>& board){
      for(int i=0;i < board.size();i++){
        if(board[i][col] == c)return false;
        if(board[row][i] == c)return false;
        if(board[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == c) return false;
      }

      return true;
    }

    bool solve(vector<vector<char>>& board){
        for(int row=0;row < 9;row++){
            for(int col=0;col < 9;col++){
                if(board[row][col] == '.'){
                    for(char c='1'; c <= '9';c++){
                        if(isValid(row, col, c, board)){
                            board[row][col] = c;
                            if(solve(board)){
                                return true;
                            }else board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
      solve(board);
    }
};