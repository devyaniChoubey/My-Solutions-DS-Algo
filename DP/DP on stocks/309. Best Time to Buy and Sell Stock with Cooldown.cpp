https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/

//Recursive
class Solution {
public:
    int solve(int i, int canBuy, vector<int>& prices){
        int n = prices.size();

        if(i  >= n) return 0;

        if(canBuy){
            int buy = -prices[i] + solve(i+1, 0, prices);
            int notBuy = solve(i+1, 1, prices);
            return max(buy, notBuy);
        }else {
            int sell = +prices[i] + solve(i+2, 1, prices);
            int notSell = solve(i+1, 0, prices);
            return max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        return solve(0, 1, prices);
    }
};



//Memoised

class Solution {
public:
    int solve(int i, int canBuy, vector<int>& prices,vector<vector<int>>&dp){
        int n = prices.size();

        if(i  >= n) return 0;

        if(dp[i][canBuy] != -1) return dp[i][canBuy];
        if(canBuy){
            int buy = -prices[i] + solve(i+1, 0, prices,dp);
            int notBuy = solve(i+1, 1, prices,dp);
            return dp[i][canBuy] = max(buy, notBuy);
        }else {
            int sell = +prices[i] + solve(i+2, 1, prices,dp);
            int notSell = solve(i+1, 0, prices,dp);
            return dp[i][canBuy] = max(sell, notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>dp(n+1, vector<int>(2, -1));
        return solve(0, 1, prices, dp);
    }
};
