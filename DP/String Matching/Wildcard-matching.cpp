https://leetcode.com/submissions/detail/979241489/

class Solution {
public:
    int solve(int pos1, int pos2 ,string p, string s,vector<vector<int>>&dp){
      if(pos1 == 0 && pos2 == 0) return true;
      if(pos1 == 0 && pos2 > 0) return false;
      if(pos1 > 0 && pos2 == 0) {
        for(int i=1;i < pos1+1;i++){
          if(p[i-1] != '*') return false;
        }
        return true;
      }
      
      if(dp[pos1][pos2] != -1) return dp[pos1][pos2];
      if(p[pos1-1] == s[pos2-1] || p[pos1-1] == '?') return dp[pos1][pos2] = solve(pos1-1, pos2-1, p,s,dp);
      if(p[pos1-1] == '*') return dp[pos1][pos2] = solve(pos1-1, pos2, p,s,dp) || solve(pos1, pos2-1, p,s,dp);


      return false;
    }
    bool isMatch(string s, string p) {
      int n = s.length();
      int m = p.length();
      vector<int>cur(n+1, 0), prev(n+1, 0);

      cur[0] = 1;prev[0] = 1;
      for(int i=1;i < m+1;i++){
        cur[0] = prev[0] && (p[i-1] == '*');
        for(int j=1;j < n+1;j++){
          if(p[i-1] == s[j-1] || p[i-1] == '?') cur[j] = prev[j-1];
          else if(p[i-1] == '*'){
            cur[j] = prev[j] || cur[j-1];
          }else cur[j] = false;
        }
        prev = cur;
      }

      return cur[n];
    }
};