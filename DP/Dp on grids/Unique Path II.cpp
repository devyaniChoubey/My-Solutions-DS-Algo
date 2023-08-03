https://leetcode.com/problems/unique-paths-ii/description/

//Recursive

class Solution {
public:
    int uniquePathHelper(int i, int j,vector<vector<int>>& obstacleGrid){
       if(i < 0 || j < 0) return 0;
       if(obstacleGrid[i][j] == 1) return 0;
       if(i == 0 && j == 0) return 1;
    
       int up = uniquePathHelper(i-1, j, obstacleGrid);
       int down = uniquePathHelper(i, j-1, obstacleGrid);

       return up + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        return uniquePathHelper(n-1, m-1,obstacleGrid);
    }
};


//Memoised

class Solution {
public:
    int uniquePathHelper(int i, int j,vector<vector<int>>& obstacleGrid,vector<vector<int>>&dp){
       if(i < 0 || j < 0) return 0;
       if(obstacleGrid[i][j] == 1) return 0;
       if(i == 0 && j == 0) return 1;

       if(dp[i][j] != -1)  return dp[i][j];

       int up = uniquePathHelper(i-1, j, obstacleGrid,dp);
       int down = uniquePathHelper(i, j-1, obstacleGrid,dp);

       return dp[i][j] = up + down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, -1));
        return uniquePathHelper(n-1, m-1,obstacleGrid, dp);
    }
};



//Dp

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        for(int i=0; i < n;i++){
            for(int j=0; j < m;j++){
                if(obstacleGrid[i][j] == 1) continue;
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, up = 0;
                    if(i > 0) up = dp[i-1][j];
                    if(j > 0) left = dp[i][j-1];
                    dp[i][j] = left + up;
                }
            }
        }

        return dp[n-1][m-1];
    }
};
