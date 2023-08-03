https://leetcode.com/problems/minimum-path-sum/

//Recursive

class Solution {
public:
    int minPath(int i, int j, vector<vector<int>>& grid){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return INT_MAX;

        int up = minPath(i-1, j, grid);
        int left = minPath(i, j-1, grid);
        return grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        return minPath(n-1, m-1, grid);
    }
};


//Memoised

class Solution {
public:
    int minPath(int i, int j, vector<vector<int>>& grid, vector<vector<int>>&dp){
        if(i == 0 && j == 0) return grid[i][j];
        if(i < 0 || j < 0) return INT_MAX;

        if(dp[i][j] != -1) return dp[i][j];
        int up = minPath(i-1, j, grid,dp);
        int left = minPath(i, j-1, grid,dp);
        return dp[i][j] = grid[i][j] + min(up, left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return minPath(n-1, m-1, grid, dp);
    }
};

//DP

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        for(int i=0;i < n;i++){
            for(int j=0;j < m;j++){
                if(i == 0 && j == 0) dp[i][j] = grid[i][j];
                else{
                    int left = INT_MAX, up = INT_MAX;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];

                    dp[i][j] = grid[i][j] + min(up, left);
                }
            }
        }
        return dp[n-1][m-1];
    }
};