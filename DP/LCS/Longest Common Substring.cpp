https://practice.geeksforgeeks.org/problems/longest-common-substring1452/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


class Solution{
    public:
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
        int maxLen = 0;
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i <= n;i++){
            for(int j=0;j <= m;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
                else{
                    if(S1[i-1] == S2[j-1]){
                        dp[i][j] = 1 + dp[i-1][j-1];
                        maxLen = max(dp[i][j], maxLen);
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        
        return maxLen;
    }
};