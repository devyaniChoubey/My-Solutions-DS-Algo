https://leetcode.com/problems/path-with-maximum-gold/

class Solution {
public:
    int solve(int i, int j,vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();

        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return 0;

        int curVal = grid[i][j];
        grid[i][j] = 0;
        int down = solve(i+1, j, grid);
        int up = solve(i-1, j, grid);
        int left = solve(i, j-1, grid);
        int right = solve(i, j+1, grid);

        
        grid[i][j] = curVal;

        return curVal + max({down, left, up, right});

    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;

        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(grid[i][j] != 0){
                    ans = max(ans, solve(i, j, grid));
                }
            }
        }

        return ans;
    }
};