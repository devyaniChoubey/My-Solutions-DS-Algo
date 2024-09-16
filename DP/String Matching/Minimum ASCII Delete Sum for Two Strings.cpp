https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/

class Solution {
public:
    int solve(string &s1, string &s2, int n, int m,vector<vector<int>>&dp){
        if(n == 0) {
            int res = 0;
            for(int i=0;i < m;i++) res += s2[i];
            return res;
        }
        if(m == 0) {
            int res = 0;
            for(int i=0;i < n;i++) res += s1[i];
            return res;
        }

        if(dp[n][m] != -1) return dp[n][m];

        if(s1[n-1] == s2[m-1]) return dp[n][m] = solve(s1,s2, n-1, m-1,dp);
        return dp[n][m] = min({s2[m-1] + solve(s1,s2, n, m-1,dp),s1[n-1] + solve(s1,s2, n-1, m,dp)});
    }
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(s1, s2, s1.length() , s2.length(),dp);
    }
};