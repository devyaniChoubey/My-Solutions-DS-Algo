https://www.geeksforgeeks.org/problems/minimal-cost/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimal-cost

class Solution {
  public:
    int solve(int n, vector<int>& arr, int k,vector<int>&dp){
        if(n == 0) return 0;
        if(n < 0) return 1e9;
        
        int steps = 1e9;
        
        if(dp[n] != -1) return dp[n];
        
        for(int i=k;i >= 1;i--){
            if(n >= i)steps = min(steps, abs(arr[n] - arr[n-i]) + solve(n-i, arr, k,dp));
        }
        
        return dp[n] = steps;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        int n = arr.size();
        vector<int>dp(n, -1);
        return solve(n-1, arr, k,dp);
    }
};