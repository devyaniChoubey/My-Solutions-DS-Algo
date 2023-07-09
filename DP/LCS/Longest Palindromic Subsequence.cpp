https://leetcode.com/submissions/detail/978327221/

class Solution {
public:
    int longestPalindromeSubseq(string s) {
      string s1 = s;
      reverse(s.begin(), s.end());
      int pos1 = s1.length();
      vector<vector<int>>dp(pos1+1, vector<int>(pos1+1, 0));
      for(int i=0;i < pos1+1;i++){
        for(int j=1;j < pos1+1;j++){
          if(i==0) dp[i][j] = 0;
          else{
            if(s[i-1] == s1[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }

      return dp[pos1][pos1];
    }
};