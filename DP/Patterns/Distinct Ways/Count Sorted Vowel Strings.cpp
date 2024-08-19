https://leetcode.com/problems/count-sorted-vowel-strings/


class Solution {
public:
    int solve(int ind, int n,vector<vector<int>>&dp){
        if(n == 0) return 1;
        if(n < 0) return 0;

        if(dp[ind][n] != -1) return dp[ind][n];

        int cnt = 0;

        for(int i=ind;i < 5;i++){
            cnt += solve(i, n-1,dp);
        }

       return dp[ind][n] = cnt;
    }
    int countVowelStrings(int n) {
        vector<vector<int>>dp(5, vector<int>(n+1, -1));
        return solve(0,n, dp);
    }
};