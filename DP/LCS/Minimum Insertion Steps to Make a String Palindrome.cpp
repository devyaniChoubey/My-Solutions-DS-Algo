https://leetcode.com/submissions/detail/978384030/

https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/

// Exact same code of [06 Min no of deletions to make a string palindrome.cpp]
class Solution {
public:
    int minInsertions(string s) {
        string s1 = s;
        reverse(s1.begin(), s1.end());
        int n = s.length();

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i=0;i <= n;i++){
            for(int j=0;j <= n;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    if(s1[i-1] == s[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                    else dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
                }
            } 
        }

        return n - dp[n][n];
    }
};