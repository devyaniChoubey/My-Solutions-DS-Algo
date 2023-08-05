https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/description/

class Solution {
public:
    int solve(int i, int canBuy, int transactionCap, vector<int>& prices){
        int n = prices.size();

        if(i  >= n || transactionCap <= 0) return 0;

        if(canBuy){
            int buy = -prices[i] + solve(i+1, 0, transactionCap, prices);
            int notBuy = solve(i+1, 1, transactionCap, prices);
            return max(buy, notBuy);
        }else {
            int sell = +prices[i] + solve(i+1, 1, transactionCap-1, prices);
            int notSell = solve(i+1, 0, transactionCap, prices);
            return max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0, 1, 2, prices);
    }
};


//Memoised

class Solution {
public:
    int solve(int i, int canBuy, int transactionCap, vector<int>& prices,vector<vector<vector<int>>>&dp){
        int n = prices.size();

        if(i  >= n || transactionCap <= 0) return 0;

        if(dp[i][canBuy][transactionCap] != -1) return dp[i][canBuy][transactionCap];
        if(canBuy){
            int buy = -prices[i] + solve(i+1, 0, transactionCap, prices,dp);
            int notBuy = solve(i+1, 1, transactionCap, prices,dp);
            return dp[i][canBuy][transactionCap] = max(buy, notBuy);
        }else {
            int sell = +prices[i] + solve(i+1, 1, transactionCap-1, prices,dp);
            int notSell = solve(i+1, 0, transactionCap, prices,dp);
            return dp[i][canBuy][transactionCap] = max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, prices, dp);
    }
};