https://leetcode.com/problems/word-search/description/

class Solution {
public:

    bool solve(int ind, int row, int col, vector<vector<char>>& board,vector<vector<int>>&vis, string &s){

        if(ind >= s.size()) {
            return true;
        }

        int m = board.size();
        int n = board[0].size();
        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, 1, 0, -1};

        vis[row][col] = 1;

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow < 0 || nRow >= m || nCol < 0 || nCol >= n) continue;
            if(board[nRow][nCol] == s[ind] && vis[nRow][nCol] == 0){

                if(solve(ind+1, nRow, nCol, board,vis,s)){return true;}
                else vis[nRow][nCol] = 0;
            }
        }

        return false;
    }
    bool exist(vector<vector<char>>& board, string s) {
        int m = board.size();
        int n = board[0].size();

        vector<vector<int>>vis(m+1, vector<int>(n+1, 0));
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(board[i][j] == s[0]){
                    if(solve(1, i, j, board, vis, s)){ return true;}
                    else vis[i][j] = 0;
                }
            }
        }

        return false;
    }
};