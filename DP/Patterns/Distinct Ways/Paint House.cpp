https://leetcode.com/problems/paint-house/?envType=company&envId=google&favoriteSlug=google-six-months&status=TO_DO&difficulty=EASY%2CMEDIUM

class Solution {
public:
    int solve(int ind,int houseInd, vector<vector<int>>& costs,vector<vector<int>>&dp){
        int cost = 1e9;

        if(houseInd >= costs.size()) return 0;

        if(dp[houseInd][ind] != -1) return dp[houseInd][ind];

        for(int i=0;i < 3;i++){
           if(i != ind)cost = min(cost, costs[houseInd][i] + solve(i,houseInd+1, costs,dp));
        }

        return dp[houseInd][ind] = cost;
    }
    int minCost(vector<vector<int>>& costs) {
        int cost = 1e9;
        int n = costs.size();

        vector<vector<int>>dp(n, vector<int>(3, -1));
        for(int i=0;i < 3;i++){
           cost = min(cost, costs[0][i] + solve(i,1, costs,dp));
        }

        return cost;
    }
};