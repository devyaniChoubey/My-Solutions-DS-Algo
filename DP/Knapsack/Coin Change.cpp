https://leetcode.com/problems/coin-change/

//Recursive

class Solution {
public:
    int solve(int n,int amount, vector<int>& coins){
        if(n == 0 && amount == 0) return 0;
        if(n == 0) return 1e9;
        if(amount == 0) return 0;
        
        int pick = 1e9;
        if(coins[n-1] <= amount) pick = 1+solve(n, amount-coins[n-1], coins);
 
        int notPick = solve(n-1,amount, coins);

        return min(pick, notPick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        int ans = solve(n, amount, coins);
        if(ans != 1e9) return ans;
        return -1;
    }
};


//Memoised

class Solution {
public:
    int solve(int n,int amount, vector<int>& coins,vector<vector<int>>&dp){
        if(n == 0 && amount == 0) return 0;
        if(n == 0) return 1e9;
        if(amount == 0) return 0;
        
        if(dp[n][amount] != -1) return dp[n][amount];
        int pick = 1e9;
        if(coins[n-1] <= amount) pick = 1+solve(n, amount-coins[n-1], coins,dp);
 
        int notPick = solve(n-1,amount, coins, dp);

        return dp[n][amount] = min(pick, notPick);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        int ans = solve(n, amount, coins, dp);
        if(ans != 1e9) return ans;
        return -1;
    }
};