https://leetcode.com/problems/coin-change-ii/

//Recursive
class Solution {
public:
    int solve(int n, int amount, vector<int>& coins){
        if(amount == 0) return 1;
        if(n == 0) return 0;

        int pick = 0;
        if(coins[n-1] <= amount) pick = solve(n, amount - coins[n-1], coins);

        int notPick = solve(n - 1, amount, coins);

        return pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        return solve(n,amount, coins);
    }
};


//Memoised
class Solution {
public:
    int solve(int n, int amount, vector<int>& coins,vector<vector<int>>&dp){
        if(amount == 0) return 1;
        if(n == 0) return 0;
        
        if(dp[n][amount] != -1) return dp[n][amount];
        int pick = 0;
        if(coins[n-1] <= amount) pick = solve(n, amount - coins[n-1], coins,dp);

        int notPick = solve(n - 1, amount, coins,dp);

        return dp[n][amount] = pick + notPick;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>>dp(n+1, vector<int>(amount+1, -1));
        return solve(n,amount, coins, dp);
    }
};