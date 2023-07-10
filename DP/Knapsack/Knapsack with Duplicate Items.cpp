https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

class Solution{
public:
    int solve(int n, int W, int val[], int wt[], vector<vector<int>>&dp){
        if(n == 0)return 0;
        if(W == 0)return 0;
        
        //pick the same item again
        if(dp[n][W] != -1) return dp[n][W];
        int pick = INT_MIN;
        if(wt[n-1] <= W) pick = val[n-1] + solve(n, W-wt[n-1], val, wt,dp);
        
        //do not pick the item at all
        int notPick = solve(n-1, W, val, wt,dp);
        
        return dp[n][W] = max(pick, notPick);
    }
    
    int knapSack(int N, int W, int val[], int wt[])
    {
       vector<vector<int>>dp(N+1, vector<int>(W+1, -1));
       return solve(N, W, val, wt, dp);
    }
};