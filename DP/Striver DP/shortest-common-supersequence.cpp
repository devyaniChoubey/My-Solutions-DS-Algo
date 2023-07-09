https://leetcode.com/submissions/detail/978491737/

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
      int pos1 = str1.length();
      int pos2 = str2.length();

      vector<vector<int>>dp(pos1+1, vector<int>(pos2+1, 0));
      for(int i=0;i < pos1+1; i++){
        for(int j=1;j < pos2+1; j++){
          if(i==0) dp[i][j] = 0;
          else{
            if(str1[i-1] == str2[j-1]){
              dp[i][j] = 1 + dp[i-1][j-1];
            }else{
              dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
          }
            
        }
      }

      int i=pos1, j = pos2;

      string ans = "";
      while(i > 0 && j > 0){
        if(str1[i-1] == str2[j-1]){
          ans.push_back(str1[i-1]);
          i--;j--;
        }else{
          if(dp[i-1][j] > dp[i][j-1]){
            ans.push_back(str1[i-1]);
            i--;
          }else{
            ans.push_back(str2[j-1]);
            j--;
          }
        }
      }

      while(i > 0){
        ans.push_back(str1[i-1]);
        i--;
      }

      while(j > 0){
        ans.push_back(str2[j-1]);
        j--;
      }
      
      reverse(ans.begin(), ans.end());
      return ans;
    }
};