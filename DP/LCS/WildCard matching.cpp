https://leetcode.com/problems/wildcard-matching/

//Recursive

class Solution {
public:
    int solve(string s, string p, int n, int m){
        if(n == 0 && m == 0) return 1;
        if(n == 0){
            for(int i=0;i < m;i++){
                if(p[i] != '*') return 0;
            }
            return 1;
        }
        else if(m == 0 && n > 0) return 0;

        if(s[n-1] == p[m-1] || (p[m-1] == '?')){
            return solve(s, p, n-1, m-1);
        }else{
            if(p[m-1] == '*'){
                // Two cases if we see a '*'
                // a) We ignore ‘*’ character and move to previous character in pattern,
                // i.e., ‘*’ indicates an empty sequence.
                // b) '*' character matches with ith character in input
               return solve(s, p, n-1, m) || solve(s, p, n, m-1);
            }else return 0;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        return solve(s, p, n, m);
    }
};


//Memoised

class Solution {
public:
    int solve(string s, string p, int n, int m,vector<vector<int>>&dp){
        if(n == 0 && m == 0) return 1;
        if(n == 0){
            for(int i=0;i < m;i++){
                if(p[i] != '*') return 0;
            }
            return 1;
        }
        else if(m == 0) return 0;

        if(dp[n][m] != -1) return dp[n][m];
        if(s[n-1] == p[m-1] || (p[m-1] == '?')){
            return dp[n][m] = solve(s, p, n-1, m-1,dp);
        }else{
            if(p[m-1] == '*'){
               return dp[n][m] = solve(s, p, n-1, m,dp) || solve(s, p, n, m-1,dp);
            }else return 0;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(s, p, n, m, dp);
    }
};


//DP

class Solution {
public:

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
        for(int i=0;i <= n;i++){
            for(int j=0;j <= m;j++){
                if(i == 0){
                    if(j == 0) dp[i][j] = 1;
                    else{
                        int flag = 1;
                        for(int k=0;k < j;k++){
                            if(p[k] != '*') flag = 0;
                        } 
                        dp[i][j] = flag;
                    }
                }else if(j == 0){
                    dp[i][j] = 0;
                }else{
                    if((s[i-1] == p[j-1]) || (p[j-1] == '?')){
                        dp[i][j] = dp[i-1][j-1];
                    }else{
                        if(p[j-1] == '*'){
                            dp[i][j] = dp[i-1][j] || dp[i][j-1];
                        }else{
                            dp[i][j] = 0;
                        }
                    }
                }
            } 
        }
        return dp[n][m];
    }
};