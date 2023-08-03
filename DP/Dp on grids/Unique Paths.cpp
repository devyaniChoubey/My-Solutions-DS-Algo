https://leetcode.com/problems/unique-paths/

//Recursive code

class Solution {
public:
    int uniquePathHelper(int m, int n) {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        int up = uniquePathHelper(m-1, n);
        int down = uniquePathHelper(m, n-1);

        return up + down;
    }
    int uniquePaths(int m, int n) {
        return uniquePathHelper(m-1, n-1);
    }
};


//Memoised

class Solution {
public:
    int uniquePathHelper(int m, int n, vector<vector<int>>&dp) {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;

        if(dp[m][n] != -1) return dp[m][n];

        int up = uniquePathHelper(m-1, n, dp);
        int down = uniquePathHelper(m, n-1, dp);

        return dp[m][n] = up + down;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, -1));
        return uniquePathHelper(m-1, n-1, dp);
    }
};


//Dp

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m, vector<int>(n, 0));
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(i == 0 && j == 0) dp[i][j] = 1;
                else{
                    int left = 0, up = 0;
                    if(i > 0) left = dp[i-1][j];
                    if(j > 0)  up = dp[i][j-1];
                    dp[i][j] =  left + up;
                }
            }
        }

        return dp[m-1][n-1];
    }
};

//Space optimised

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int>prev(n, 0);
        for(int i=0;i < m;i++){
            for(int j=0;j < n;j++){
                if(i == 0 && j == 0) prev[j] = 1;
                else{
                    int left = 0, up = 0;
                    if(i > 0) up = prev[j];
                    if(j > 0) left = prev[j-1];
                    prev[j] = up+left;
                }
            }
        }

        return prev[n-1];
    }
};