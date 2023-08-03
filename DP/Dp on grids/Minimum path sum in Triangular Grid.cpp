https://leetcode.com/problems/triangle/


//Recursive
class Solution {
public:
    int minimumTotalHelper(int i, int j, vector<vector<int>>& triangle){
        if(i == triangle.size() - 1) return triangle[i][j];

        int down = minimumTotalHelper(i+1, j, triangle);
        int diagonal = minimumTotalHelper(i+1, j+1, triangle);

        return triangle[i][j] + min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
       int m = triangle[0].size();
       return minimumTotalHelper(0, 0, triangle);
    }
};


//Memoised

class Solution {
public:
    int minimumTotalHelper(int i, int j, vector<vector<int>>& triangle, vector<vector<int>>&dp){
        if(i == triangle.size() - 1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down = minimumTotalHelper(i+1, j, triangle,dp);
        int diagonal = minimumTotalHelper(i+1, j+1, triangle,dp);

        return dp[i][j] = triangle[i][j] + min(down, diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
       vector<vector<int>>dp(n, vector<int>(n, -1));
       return minimumTotalHelper(0, 0, triangle, dp);
    }
};


//DP

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i=n-1;i >= 0;i--){
            for(int j=i;j >= 0;j--){
                if(i == n-1) dp[i][j] = triangle[i][j];
                else{
                   dp[i][j] = triangle[i][j] + min(dp[i+1][j] , dp[i+1][j+1]);
                }
            }
        }
       return dp[0][0];
    }
};