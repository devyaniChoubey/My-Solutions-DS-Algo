https://leetcode.com/submissions/detail/977943760/

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