https://leetcode.com/problems/number-of-islands/submissions/991731733/

void coundIslandsDFS(int row, int col, vector<vector<int>>&vis, vector<vector<char>>& grid){
    int m = grid.size();
    int n = grid[0].size();
    vis[row][col] = 1;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, -1, 0, 1};
    for(int i=0;i < 4;i++){
        int newRow = row+delRow[i];
        int newCol = col+delCol[i];
        if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && grid[newRow][newCol] == '1' && vis[newRow][newCol] == 0){
            coundIslandsDFS(newRow, newCol, vis, grid);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int numIslands = 0;
    vector<vector<int>>vis(m+1, vector<int>(n+1, 0));
    for(int i=0;i < m;i++){
        for(int j=0;j < n;j++){
            if(grid[i][j] == '1' && vis[i][j] == 0){
                coundIslandsDFS(i, j, vis, grid);
                numIslands++;
            }
        }
    }

    return numIslands;
}
