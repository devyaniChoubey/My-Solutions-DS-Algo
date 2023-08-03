https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


//Recursive
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[] , int val[] , int n){
        if(n == 0|| W==0) return 0;

        int take = -1e9;
        if(wt[n-1] <= W){
            //we can take it;
            take = val[n-1] + solve(W-wt[n-1], wt, val, n-1);
        }
        int notTake = 0 + solve(W, wt, val, n-1);
        
        return max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       return solve(W, wt, val, n);
       // Your code here
    }
};


//Memoised
class Solution
{
    public:
    
    //Function to return max value that can be put in knapsack of capacity W.
    int solve(int W, int wt[] , int val[] , int n, vector<vector<int>>&dp){
        if(n == 0 || W == 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        int take = -1e9;
        if(wt[n-1] <= W){
            //we can take it;
            take = val[n-1] + solve(W-wt[n-1], wt, val, n-1,dp);
        }
        
        int notTake = 0 + solve(W, wt, val, n-1,dp);
        
        return dp[n][W] = max(take, notTake);
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1, vector<int>(W+1, -1));
       return solve(W, wt, val, n, dp);
       // Your code here
    }
};


//DP

class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
       
       for(int i=0;i <= n;i++){
           for(int j=0;j <= W;j++){
               if(i == 0 || j == 0) dp[i][j] = 0;
               else{
                   int take = -1e9;
                   if(wt[i-1] <= j) take = val[i-1] + dp[i-1][j-wt[i-1]];
                   
                   int notTake = dp[i-1][j];
                   
                   dp[i][j] = max(take, notTake);
               }
           }
       }
       return dp[n][W];
       // Your code here
    }
};
