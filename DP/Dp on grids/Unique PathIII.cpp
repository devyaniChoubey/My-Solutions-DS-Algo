https://leetcode.com/problems/unique-paths-iii/description/

class Solution {
public:
    int empty = 0;
    int uniquePathsIII(vector<vector<int>>& grid) {
        int startX, startY;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(grid[i][j] == 1){
                    startX = i;
                    startY = j;
                }else if(grid[i][j] == 0) empty++;
            }
        }
        int res = 0;
        dfs(startX, startY, res, grid);
        return res;
    }

    void dfs(int i, int j, int &res, vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        if(i < 0 || j < 0 || i >= n || j >= m || grid[i][j] < 0){
            return;
        }

        if(grid[i][j] == 2){
            if(empty == 0) res++;
            return;
        }

        if(grid[i][j] != 1) empty--;
        grid[i][j] = -2;

        dfs(i+1, j, res, grid);
        dfs(i, j+1, res, grid);
        dfs(i-1, j, res, grid);
        dfs(i, j-1, res, grid);
       
        empty++;
        grid[i][j] = 0;   
    }

};