https://leetcode.com/problems/n-queens/

class Solution {
public:
    void solve(int col, vector<string>&board, vector<vector<string>>&ans,vector<int>&lowerDiagonal,vector<int>&upperDiagonal, vector<int>&leftRow){
        int n = board.size();
        if(col >= n){
            ans.push_back(board);
        }

        for(int row=0;row < n;row++){
            if(leftRow[row] == 0 && lowerDiagonal[col+row] == 0 && upperDiagonal[n-1+col-row] == 0){
                board[row][col] = 'Q';
                leftRow[row] = 1;
                lowerDiagonal[col+row] = 1;
                upperDiagonal[n-1+col-row] = 1;
                solve(col+1, board, ans,lowerDiagonal,upperDiagonal,leftRow);
                board[row][col] = '.';
                leftRow[row] = 0;
                lowerDiagonal[col+row] = 0;
                upperDiagonal[n-1+col-row] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n);
        string s(n, '.');
        for(int i=0;i < n;i++){
            board[i] = s;
        }
        vector<int>lowerDiagonal(2*n - 1, 0), upperDiagonal(2*n - 1, 0), leftRow(n, 0);
        solve(0, board, ans, lowerDiagonal,upperDiagonal,leftRow);
        return ans;
    }
};