https://leetcode.com/problems/climbing-stairs/description/

class Solution {
public:
    int solve(int n,vector<int>&dp){
        if(n <= 0) return 1;

        if(dp[n] != -1) return dp[n];
        int twoSteps = 0, oneStep = 0;
        
        if(n >= 2) twoSteps = solve(n-2,dp);
        if(n >= 1) oneStep = solve(n-1,dp);

        return dp[n] = twoSteps + oneStep;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1, -1);
        return solve(n, dp);
    }
};