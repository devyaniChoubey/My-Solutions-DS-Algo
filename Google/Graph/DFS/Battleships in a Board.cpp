https://leetcode.com/problems/battleships-in-a-board/description/

https://leetcode.com/problems/battleships-in-a-board/solutions/1409456/tc-o-n-m-sc-o-1-complete-explanation-simple-iterative-without-dfs-bfs/

class Solution {
public:

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int battleshipCnt = 0;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(board[i][j] == '.') continue;
                if(i > 0 && board[i-1][j] == 'X') continue;
                if(j > 0 && board[i][j-1] == 'X') continue;

                battleshipCnt++;
            }
        }

        return battleshipCnt;
    }
};



//DFS

class Solution {
public:
    void dfs(int row, int col, vector<vector<char>>& board){
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = { 0, 1, 0, -1};

        int m = board.size();
        int n = board[0].size();

        board[row][col] = '.';

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            
            if(nRow < 0 || nCol < 0 || nRow > m-1 || nCol > n-1) continue;

            if(board[nRow][nCol] == 'X') dfs(nRow, nCol, board);

        }
    }
    int countBattleships(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        int battleshipCnt = 0;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(board[i][j] == 'X'){
                    battleshipCnt++;
                    dfs(i, j, board);
                }
            }
        }

        return battleshipCnt;
    }
};