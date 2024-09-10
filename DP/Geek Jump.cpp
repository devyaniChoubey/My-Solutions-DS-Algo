https://www.geeksforgeeks.org/problems/geek-jump/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=geek-jump

class Solution {
  public:
    int solve(int n, vector<int>& height,vector<int>&dp){
        if(n == 0) return 0;
        if(n < 0) return 1e9;
        
        if(dp[n] != -1) return dp[n];
        
        int oneStep = 1e9, twoStep = 1e9;
        if(n-2 >= 0) twoStep = abs(height[n] - height[n-2]) + solve(n-2, height,dp);
        if(n-1 >= 0) oneStep = abs(height[n] - height[n-1]) + solve(n-1, height,dp);
        
        return dp[n] = min(twoStep, oneStep);
        
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n, -1);
        return solve(n-1, height,dp);
    }
};