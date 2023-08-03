https://leetcode.com/problems/minimum-falling-path-sum/


//Recursive
class Solution {
public:
    int minPathSum(int i, int j, vector<vector<int>>& matrix){
        int n = matrix.size();
        if(j < 0 || j > n-1) return INT_MAX;
        if(i == n-1) return matrix[i][j];

        int leftDiag = minPathSum(i+1, j-1, matrix);
        int rightDiag = minPathSum(i+1, j+1, matrix);
        int down = minPathSum(i+1, j, matrix);

        return matrix[i][j] + min(leftDiag , min(rightDiag, down));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        for(int j=0;j < n;j++){
           ans = min(ans, minPathSum(0, j, matrix));
        }

        return ans;
    }
};



//Memoised

class Solution {
public:
    int minPathSum(int i, int j, vector<vector<int>>& matrix,vector<vector<int>>& dp){
        int n = matrix.size();
        if(j < 0 || j > n-1) return INT_MAX;
        if(i == n-1) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int leftDiag = minPathSum(i+1, j-1, matrix,dp);
        int rightDiag = minPathSum(i+1, j+1, matrix,dp);
        int down = minPathSum(i+1, j, matrix,dp);

        return dp[i][j] = matrix[i][j] + min(leftDiag , min(rightDiag, down));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = INT_MAX;
        vector<vector<int>>dp(n, vector<int>(n, -1));
        for(int j=0;j < n;j++){
           ans = min(ans, minPathSum(0, j, matrix, dp));
        }

        return ans;
    }
};


//DP

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int ans = 1e7;
        vector<vector<int>>dp(n, vector<int>(n, 0));
        
        for(int i=n-1;i >= 0;i--){
            for(int j=n-1;j >= 0;j--){
                if(i == n-1) dp[i][j] = matrix[i][j];
                else{
                    int leftDiag = 1e7;
                    int rightDiag = 1e7;

                    if(j > 0) leftDiag = dp[i+1][j-1];
                    if(j < n-1) rightDiag = dp[i+1][j+1];

                    dp[i][j] = matrix[i][j] + min(dp[i+1][j] , min(leftDiag, rightDiag));
                }
            }
        }

        for(int j=0;j < n;j++) ans = min(ans, dp[0][j]);
        return ans;
    }
};