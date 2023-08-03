// https://practice.geeksforgeeks.org/problems/rod-cutting0840/1
// https://www.techiedelight.com/rod-cutting/

/*
Given a rod of length n and a list of rod prices of length i, where 1 <= i <= n, 
find the optimal way to cut the rod into smaller rods to maximize profit.
*/

/*
This problem is very similar to the Unbounded Knapsack Problem, where there are multiple occurrences of the same item. Here the pieces of the rod.

An analogy between Unbounded Knapsack and the Rod Cutting Problem:

______________________________________________________________________________________________________
Unbounded Knapsack Problem                    |       Rod Cutting Problem
______________________________________________________________________________________________________
Size of array (n)                             |       Length of rod (n)
Value of the item (value[])                   |       Price of the pieces of rod (price[])
Weight array (weitht[])                       |       Length of array (length[])
Max knapsack capacity (W)                     |       Length of main rod (n == mxLength)
______________________________________________________________________________________________________
*/

class Solution{
  public:
    int solve(int n, int len, vector<int>&length, int price[]){
        if(n == 0 || len == 0) return 0;
        
        int take = -1e9;
        
        if(length[n-1] <= len) take = price[n-1] + solve(n, len-length[n-1], length, price);
        
        int notTake = solve(n-1, len, length, price);
        
        return max(take, notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<int>length(n);
        for(int i=0;i < n;i++) length[i] = i+1;
        return solve(n, n, length, price);
    }
};


//Memoised

class Solution{
  public:
    int solve(int n, int len,vector<int>&length, int price[],vector<vector<int>>&dp){
        if(n == 0 || len == 0) return 0;
        
        if(dp[n][len] != -1) return dp[n][len];
        
        int take = -1e9;
        if(length[n-1] <= len) take = price[n-1] + solve(n,len-length[n-1],length, price,dp);
        
        int notTake = solve(n-1,len,length, price,dp);
        
        return dp[n][len] = max(take, notTake);
    }
    int cutRod(int price[], int n) {
        //code here
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        vector<int>length(n);
        for(int i=0;i < n;i++) length[i] = i+1;
        return solve(n, n,length, price,dp);
    }
};
