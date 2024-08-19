https://leetcode.com/problems/2-keys-keyboard/?envType=daily-question&envId=2024-08-19

class Solution {
public:
    int solve(int curLen, int copiedLength, int n,vector<vector<int>>&dp){
        if(curLen == n) {
            return 0;
        }
        if(curLen > n) {
            return 1e9;
        }

        if(dp[curLen][copiedLength] != -1) return dp[curLen][copiedLength];

        int mini = 1e9;

        if(copiedLength > 0){
            // paste
            mini = min(mini,1 + solve(copiedLength+curLen, copiedLength, n,dp));
        }
        
        // copy all + paste
        mini = min(mini,2 + solve(2*curLen, curLen, n,dp));

        return dp[curLen][copiedLength] = mini;
    }
    int minSteps(int n) {
        vector<vector<int>>dp(n+1, vector<int>(n, -1));
        return solve(1,0, n,dp);
    }
};