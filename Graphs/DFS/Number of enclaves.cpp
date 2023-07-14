https://leetcode.com/problems/number-of-enclaves/description/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>&vis, vector<vector<int>>&grid){
        vis[row][col] = 1;
        grid[row][col] = 0;
        int m = grid.size();
        int n = grid[0].size();

        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, 1 , 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 1 && vis[nRow][nCol] == 0){
                dfs(nRow, nCol, vis, grid);
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>vis(m , vector<int>(n, 0));

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(i==0 || j==0 || i == m-1 || j == n-1){
                    if(grid[i][j] == 1 && vis[i][j] == 0){
                        dfs(i, j , vis, grid);
                    }
                }
            }
        }

        int landCell = 0;
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    landCell++;
                }
            }
        }

        return landCell;
    }
};