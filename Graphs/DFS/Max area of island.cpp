https://leetcode.com/problems/max-area-of-island/description/

class Solution {

public:
    void dfs(int row, int col,int &cnt, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        grid[row][col] = 0;
        cnt++;

        int delRow[] = {-1, 0, 1 , 0};
        int delCol[] = {0, 1, 0, -1};

        for(int i=0;i < 4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];

            if(nRow < 0 || nRow >= m || nCol < 0 || nCol >= n) continue;
            if(grid[nRow][nCol] == 1) dfs(nRow, nCol,cnt, grid);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maxArea = 0;
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] == 1){
                    int cnt = 0;
                    dfs(i, j, cnt, grid);
                    maxArea = max(maxArea, cnt);
                }
            }
        }

        return maxArea;
    }
};