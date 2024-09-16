https://leetcode.com/submissions/detail/979047173/

class Solution {
public:
    int solve(int pos1, int pos2, string word1, string word2,vector<vector<int>>&dp){
      if(pos1 == 0) return pos2;
      if(pos2 == 0) return pos1;

      if(dp[pos1][pos2] != -1)return dp[pos1][pos2];
      int match = solve(pos1-1, pos2-1, word1, word2,dp);
      if(word1[pos1-1] == word2[pos2-1]) return dp[pos1][pos2] = match;
      else{
        int insert = 1+solve(pos1, pos2-1, word1, word2,dp);
        int deleted = 1+solve(pos1-1, pos2, word1, word2,dp);
        return dp[pos1][pos2] = min(insert, min(deleted, 1+match));
      }
    }
    int minDistance(string word1, string word2) {
      int n = word1.length();
      int m = word2.length();
      vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
      for(int i=0;i < n+1;i++){
        for(int j=0;j < m+1;j++){
          if(i==0) dp[i][j] = j;
          else if(j==0) dp[i][j] = i;
          else{
            if(word1[i-1] == word2[j-1]) dp[i][j] = dp[i-1][j-1];
            else{
              int inserted = 1+dp[i][j-1];
              int deleted = 1+dp[i-1][j];
              int replaced = 1+dp[i-1][j-1];
              dp[i][j] = min(inserted, min(deleted, replaced));
            }
          }
        }
      }

      return dp[n][m];
    }
};