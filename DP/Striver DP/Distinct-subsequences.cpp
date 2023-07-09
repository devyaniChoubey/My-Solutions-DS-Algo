https://leetcode.com/submissions/detail/978902441/

class Solution {
public:
    int numDistinct(string s, string t) {
      int n = s.length();
      int m = t.length();

      vector<unsigned long long int>dp(m+1, 0);

      dp[0] = 1;

      for(int i=1;i < n+1;i++){
        for(int j=m;j > 0;j--){
          dp[j] = dp[j] + ((s[i-1] == t[j-1]) ? dp[j-1] : 0);
        }
      }

      return dp[m];
    }
};