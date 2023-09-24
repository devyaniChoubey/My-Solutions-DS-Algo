https://leetcode.com/problems/coloring-a-border/description/

https://leetcode.com/problems/coloring-a-border/solutions/282847/c-with-picture-dfs/

class Solution {
public:
    void dfs(int row, int col, int cl ,vector<vector<int>>& grid,vector<vector<int>>& vis){
        int n = grid.size();
        int m = grid[0].size();
        
        grid[row][col] = -cl;
        vis[row][col] = 1;

        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= m || vis[nRow][nCol] == 1 || grid[nRow][nCol] != cl) continue;

            dfs(nRow, nCol, cl, grid, vis);
        }

        if(row > 0 && row < n-1 && col > 0 && col < m-1 && abs(grid[row][col+1]) == cl && 
        abs(grid[row][col-1]) == cl && abs(grid[row+1][col]) == cl && abs(grid[row-1][col]) == cl){
            grid[row][col] = cl;
        }

    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>>vis(n, vector<int>(m, 0));

        dfs(row, col, grid[row][col],grid, vis);
        
        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(grid[i][j] < 0) grid[i][j] = color;
            }
        }

        return grid;
    }
};


