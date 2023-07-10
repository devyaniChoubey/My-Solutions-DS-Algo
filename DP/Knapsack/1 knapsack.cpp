class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    
    int solve(int W, int wt[], int val[], int n,vector<vector<int>>&dp){
        if(n <= 0 || W <= 0)return 0;
        if(dp[W][n] != -1) return dp[W][n];
        if(wt[n-1] <= W){
            //take or not take n th item
            return dp[W][n] = max((val[n-1] + solve(W-wt[n-1], wt, val, n-1,dp)), solve(W, wt, val, n-1,dp));
        }else{
            //only not take n th item
            return dp[W][n] = solve(W, wt, val, n-1,dp);
        }
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>>dp(W+1, vector<int>(n+1, -1));
        return solve(W, wt, val, n, dp);
    }
};