https://leetcode.com/submissions/detail/977943760/

https://leetcode.com/problems/longest-common-subsequence/

//Recursive
class Solution {
public:
    int solve(int n , int m , string s1, string s2){
        if(n == 0 || m == 0) return 0;

        if(s1[n-1] == s2[m-1]) return 1 + solve(n-1, m-1, s1, s2);
        else{
            return max(solve(n, m-1, s1, s2), solve(n-1, m, s1, s2));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        return solve(n, m, text1, text2);
    }
};


//Memoised

class Solution {
public:
    int solve(int n , int m , string s1, string s2,vector<vector<int>>&dp){
        if(n == 0 || m == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];
        if(s1[n-1] == s2[m-1]) return dp[n][m] = 1 + solve(n-1, m-1, s1, s2,dp);
        else{
            return dp[n][m] = max(solve(n, m-1, s1, s2,dp), solve(n-1, m, s1, s2,dp));
        }

    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, text1, text2, dp);
    }
};

//DP

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=1;i <= n;i++){
            for(int j=1;j <= m;j++){
               if(text1[i-1] == text2[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
               else{
                   dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
               }
            }
        }
        return dp[n][m];
    }
};



//Space Optimised
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
      int pos1 = text1.length();
      int pos2 = text2.length();
      vector<int>prev(pos2+1, 0);
      
      for(int i=0;i <= pos1; i++){
        vector<int>cur(pos2+1, 0);
        for(int j=1;j <= pos2; j++){
          if(i == 0) cur[j] = 0;
          else{
            if(text1[i-1] == text2[j-1]) cur[j] = 1+prev[j-1];
            else cur[j] = max(prev[j], cur[j-1]);
          }
        }
        prev = cur;
      }

      return prev[pos2];
    }
};