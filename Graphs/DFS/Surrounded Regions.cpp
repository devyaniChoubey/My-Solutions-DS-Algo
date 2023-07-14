https://leetcode.com/problems/surrounded-regions/description/


class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<char>>&board){
        int m = board.size();
        int n = board[0].size();
        vis[row][col] = 1;
        board[row][col] = '1';
        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, +1, 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >=0 && nRow < m && nCol >= 0 && nCol < n && board[nRow][nCol] == 'O' && vis[nRow][nCol] == 0){
                dfs(nRow, nCol, vis, board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>>vis(m, vector<int>(n , 0));

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(i == 0 || j == 0 || i == m - 1 || j == n - 1){
                    if(!vis[i][j] && board[i][j] == 'O'){
                        dfs(i, j, vis, board);
                    }
                }
            }
        }

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(board[i][j] == 'O')board[i][j] = 'X';
            }
        }

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(board[i][j] == '1')board[i][j] = 'O';
            }
        }

        
    }
};