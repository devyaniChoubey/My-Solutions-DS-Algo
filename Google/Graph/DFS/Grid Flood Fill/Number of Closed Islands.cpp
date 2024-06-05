https://leetcode.com/problems/number-of-closed-islands/description/

same as https://leetcode.com/problems/number-of-enclaves/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        int delRow[] = {-1,0,1,0};
        int delCol[] = {0, 1, 0, -1};

        grid[row][col] = 1;

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow < 0 || nCol < 0 || nRow >= m || nCol >= n || grid[nRow][nCol] == 1) continue;

            dfs(nRow, nCol, grid);
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        
        for(int j=0;j < n;j++){
            if(grid[0][j] == 0) dfs(0, j, grid); 
            if(grid[m-1][j] == 0) dfs(m-1, j, grid); 
        }


        for(int i=0;i < m;i++){
            if(grid[i][0] == 0) dfs(i, 0, grid); 
            if(grid[i][n-1] == 0) dfs(i, n-1, grid); 
        }

        int islandCnt = 0;


        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 0) {
                    dfs(i, j, grid);
                    islandCnt++;
                }
            }
        }

        return islandCnt;
    }
};