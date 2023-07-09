https://leetcode.com/problems/delete-operation-for-two-strings/

class Solution {
public:
    int minDistance(string word1, string word2) {
      int pos1 = word1.length();
      int pos2 = word2.length();
      vector<vector<int>>dp(pos1+1, vector<int>(pos2+1, 0));

      for(int i=0;i < pos1+1;i++){
        for(int j=1;j < pos2+1;j++){
          if(i==0) dp[i][j] = 0;
          else{
            if(word1[i-1] == word2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
          }
        }
      }

      return pos1 + pos2 - 2*(dp[pos1][pos2]);
    }
};