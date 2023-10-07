https://leetcode.com/problems/valid-sudoku/description/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        unordered_set<char>row[n], col[n] , box[n];
        for(int i=0;i < 9;i++){
            for(int j=0;j < 9;j++){
                char val = board[i][j];
                if(val == '.') continue;

                if(row[i].count(val)) return 0;
                row[i].insert(val);

                if(col[j].count(val)) return 0;
                col[j].insert(val);

                int idx = 3*(i/3) + (j/3);

                if(box[idx].count(val)) return 0;

                box[idx].insert(val);
            }
        }

        return true;
    }
};




class Solution {
public:
    bool isValid(int row, int col, vector<vector<char>>& board){
        for(int i=0;i < 9;i++){
            if(board[i][col] == board[row][col] && i != row) return false;
            if(board[row][i] == board[row][col] && i != col) return false;
        }

        for(int i=0;i < 9;i++){
            int nRow = 3*(row/3) + i/3;
            int nCol = 3*(col/3) + i%3;

            if(board[nRow][nCol] == board[row][col] && row != nRow && col != nCol) return false;
        }

        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i < 9;i++){
            for(int j=0;j < 9;j++){
                if(board[i][j] != '.' && !isValid(i, j, board)) return false;
            }
        }

        return true;
    }
};
