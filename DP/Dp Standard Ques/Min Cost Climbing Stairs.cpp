https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int solve(int ind, vector<int>& cost,vector<int>&dp){
       if(ind >= cost.size()) return 0;

       if(dp[ind] != -1) return dp[ind];

       return dp[ind] = cost[ind] + min(solve(ind+1, cost,dp) ,solve(ind+2, cost,dp));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>dp(n, -1);
        return min(solve(0, cost, dp), solve(1, cost,dp));
    }
};