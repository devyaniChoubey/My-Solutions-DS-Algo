https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int MOD = 1e9+7;
    int solve(int n, int k, int target,vector<vector<int>>&dp){
        if(n == 0 && target == 0) return 1;
        else if(n <= 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];

        int cnt = 0;

        for(int i=1;i <= k;i++){
            if(target >= i)cnt = (cnt + solve(n-1, k, target-i,dp))% MOD;
        }

        return dp[n][target] = cnt%MOD;
    }
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
        return solve(n, k, target, dp);
    }
};