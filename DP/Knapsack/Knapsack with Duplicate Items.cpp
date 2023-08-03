https://practice.geeksforgeeks.org/problems/knapsack-with-duplicate-items4201/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


//Recursive

class Solution{
public:
    int solve(int n , int W, int val[], int wt[]){
        if(n == 0 || W == 0) return 0;
        
        int take = -1e9;
        
        if(wt[n-1] <= W) take = val[n-1] + solve(n, W-wt[n-1], val, wt);
        
        int notTake = solve(n-1, W, val, wt);
        
        return max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        return solve(N, W, val, wt);
    }
};


//Memoised
class Solution{
public:
    int solve(int n , int W, int val[], int wt[],vector<vector<int>>&dp){
        if(n == 0 || W == 0) return 0;
        
        int take = -1e9;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n-1] <= W) take = val[n-1] + solve(n, W-wt[n-1], val, wt, dp);
        
        int notTake = solve(n-1, W, val, wt, dp);
        
        return dp[n][W] = max(take, notTake);
    }
    int knapSack(int N, int W, int val[], int wt[])
    {
        vector<vector<int>>dp(N+1, vector<int>(W+1, -1));
        return solve(N, W, val, wt, dp);
    }
};