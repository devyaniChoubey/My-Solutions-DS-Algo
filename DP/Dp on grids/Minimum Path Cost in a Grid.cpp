https://leetcode.com/problems/minimum-path-cost-in-a-grid/description/

//Recursive
class Solution {
public:
    int minCost(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1) return grid[i][j];

        int mini = 1e9;

        for(int j1=0;j1 < n;j1++){
            mini = min(mini, minCost(i+1, j1, grid, moveCost) + moveCost[grid[i][j]][j1]);
        }

        mini += grid[i][j];

        return mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();

        int ans = 1e9;
        for(int j=0;j < n;j++){
           ans = min(ans, minCost(0, j, grid, moveCost));
        }

        return ans;
    }
};



//Memoised

class Solution {
public:
    int minCost(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& moveCost,vector<vector<int>>&dp){
        int m = grid.size();
        int n = grid[0].size();
        if(i == m-1) return grid[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;

        for(int j1=0;j1 < n;j1++){
            mini = min(mini, minCost(i+1, j1, grid, moveCost, dp) + moveCost[grid[i][j]][j1]);
        }

        mini += grid[i][j];

        return dp[i][j] = mini;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>dp(m, vector<int>(n, -1));
        int ans = 1e9;
        for(int j=0;j < n;j++){
           ans = min(ans, minCost(0, j, grid, moveCost, dp));
        }

        return ans;
    }
};


//DP

class Solution {
public:
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<int>>dp(m, vector<int>(n, 0));

        for(int i=m-1;i >= 0;i--){
            for(int j=0;j < n;j++){
                if(i == m-1) dp[i][j] = grid[i][j];
                else{
                    int mini = 1e9;
                    for(int j1=0;j1 < n;j1++){
                        mini = min(mini, dp[i+1][j1] + moveCost[grid[i][j]][j1]);
                    }
                    mini += grid[i][j];
                    dp[i][j] = mini;
                }
            }
        }

        int ans = 1e9;
        for(int j=0;j < n;j++){
           ans = min(ans, dp[0][j]);
        }

        return ans;
    }
};