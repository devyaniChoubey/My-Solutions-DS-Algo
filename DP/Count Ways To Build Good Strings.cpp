https://leetcode.com/problems/count-ways-to-build-good-strings/

class Solution {
public:
    int MOD = 1e9+7;
    int solve(int len,int zero, int one,vector<int>&dp){
        if(len == 0) return 1;
        if(len < 0) return 0;

        if(dp[len] != -1) return dp[len];

        return dp[len] = (solve(len-zero, zero, one,dp) + solve(len-one, zero, one,dp))%MOD;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0;
        vector<int>dp(high+1, -1);

        for(int len=low;len <= high;len++){
            
            ans = (ans + solve(len, zero, one,dp))%MOD;
        }

        return ans;
    }
};