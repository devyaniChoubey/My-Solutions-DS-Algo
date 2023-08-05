https://leetcode.com/problems/edit-distance/

//Recursive

class Solution {
public:
    int solve(int n , int m , string s1, string s2){
       if(m == 0 && n == 0) return 0;
       if(n == 0) return m; //if string 1 is empty (ex.   s1="" , s2 = "ab") no. of operations = 2;
       if(m == 0) return n; //if string 2 is empty (ex.   s1="ab" , s2 = "") no. of operations = 2;

       if(s1[n-1] == s2[m-1]) return solve(n-1, m-1, s1, s2);
       else{
           int insertions = 1 + solve(n, m-1, s1, s2);
           int deletions = 1 + solve(n-1, m, s1, s2);
           int replace = 1 + solve(n-1, m-1, s1, s2);

           return min({insertions, deletions, replace});
       }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        return solve(n, m, word1, word2);
    }
};


//Memoised

class Solution {
public:
    int solve(int n , int m , string s1, string s2,vector<vector<int>>&dp){
       if(m == 0 && n == 0) return 0;
       if(n == 0) return m;
       if(m == 0) return n;

       if(dp[n][m] != -1) return dp[n][m];

       if(s1[n-1] == s2[m-1]) return solve(n-1, m-1, s1, s2, dp);
       else{
           int insertions = 1 + solve(n, m-1, s1, s2, dp);
           int deletions = 1 + solve(n-1, m, s1, s2, dp);
           int replace = 1 + solve(n-1, m-1, s1, s2, dp);

           return dp[n][m] = min({insertions, deletions, replace});
       }
    }
    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, word1, word2, dp);
    }
};


//DP

class Solution {
public:

    int minDistance(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        
        for(int i=0;i <= n;i++){
            for(int j=0;j <= m;j++){
                if(i == 0){
                    if(j == 0) dp[i][j] = 0;
                    else dp[i][j] = j;
                }else if(j == 0){
                    dp[i][j] = i;
                }else{
                    if(s1[i-1] == s2[j-1]){
                       dp[i][j] = dp[i-1][j-1];
                    }else{
                       int insertions = 1 + dp[i][j-1];
                       int deletions = 1 + dp[i-1][j];
                       int replace = 1 + dp[i-1][j-1];
                       dp[i][j] = min({insertions, deletions, replace});
                    }
                }
            }
        }

        return dp[n][m];
    }
};