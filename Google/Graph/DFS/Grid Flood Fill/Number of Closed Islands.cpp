https://leetcode.com/problems/number-of-closed-islands/description/

same as https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        grid[row][col] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid[nRow][nCol] == 0){
                dfs(nRow, nCol, grid);
            } 
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if((i == 0 || j == 0 || j == n-1 || i == m-1) && grid[i][j] == 0){
                    dfs(i, j, grid);
                }
            }
        }

        int cntClosedIsland = 0;

        for(int i=1;i < m-1;i++){
            for(int j=1;j < n-1;j++){
                if(grid[i][j] == 0){
                    dfs(i, j, grid);
                    cntClosedIsland++;
                }
            }
        }

        return cntClosedIsland;
    }
};