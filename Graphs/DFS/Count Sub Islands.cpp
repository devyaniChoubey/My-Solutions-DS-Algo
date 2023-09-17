https://leetcode.com/problems/count-sub-islands/description/

class Solution {
public:
    void dfs(int row, int col, vector<vector<int>>& grid1, vector<vector<int>>& grid2,bool &isSubIsland){
        int m = grid1.size();
        int n = grid1[0].size();

        if(grid1[row][col] == 0) isSubIsland = false;

        grid2[row][col] = 0;

        int delCol[] = {-1, 0, 1, 0};
        int delRow[] = {0, 1, 0, -1};


        for(int k=0;k < 4;k++){
            int nRow = row + delRow[k];
            int nCol = col + delCol[k];

            if(nRow >= 0 && nRow < m && nCol >= 0 && nCol < n && grid2[nRow][nCol] == 1){
                dfs(nRow, nCol, grid1, grid2,isSubIsland);
            }
        }
    } 
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid1.size();
        int n = grid1[0].size();
        int countSubIsland = 0;
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid2[i][j] == 1){
                    bool isSubIsland = true;
                    dfs(i, j, grid1,grid2, isSubIsland);
                    if(isSubIsland)countSubIsland++;
                }
            }
        }

        return countSubIsland;
    }
};