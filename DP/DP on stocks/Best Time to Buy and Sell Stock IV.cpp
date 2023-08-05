https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/description/

//Recursive

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
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        return solve(0, 1, k, prices);
    }
};




//Memoised
class Solution {
public:
    int solve(int i, int canBuy, int cap, vector<int>& prices,vector<vector<vector<int>>>&dp){
        int n = prices.size();
        if(i >= n || cap <= 0) return 0;

        if(dp[i][canBuy][cap] != -1) return dp[i][canBuy][cap];
        if(canBuy){
            int buy = -prices[i] + solve(i+1, 0, cap, prices,dp);
            int notBuy = solve(i+1, 1, cap, prices,dp);
            return dp[i][canBuy][cap] = max(buy, notBuy);
        }else{
            int sell = +prices[i] + solve(i+1, 1, cap-1, prices,dp);
            int notSell = solve(i+1, 0, cap, prices,dp);
            return dp[i][canBuy][cap] = max(sell, notSell);
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solve(0, 1, k, prices,dp);
    }
};