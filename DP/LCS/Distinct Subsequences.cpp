https://leetcode.com/problems/distinct-subsequences/

//Recursive
class Solution {
public:
    int solve(string s, string t, int n, int m){
        if(m == 0) return 1;
        if(n == 0) return 0;

        if(s[n-1] == t[m-1]){
            //take t[m-1] and reduce both strings
            int pick = solve(s, t, n-1 , m-1);

            //look for another occurence of t[m-1] in reduced string s;
            int notPick = solve(s, t, n-1 , m);

            return pick + notPick;
        }else {
            //look for another occurence of t[m-1] in reduced string s;
            return solve(s, t, n-1 , m);
        }
    }
    int numDistinct(string s, string t) {
        return solve(s, t, s.length() , t.length());
    }
};


//Memoised

class Solution {
public:
    int solve(string s, string t, int n, int m,vector<vector<int>>&dp){
        if(m == 0) return 1;
        if(n == 0) return 0;
        
        if(dp[n][m] != -1) return dp[n][m];

        if(s[n-1] == t[m-1]){
            //take t[m-1] and reduce both strings
            int pick = solve(s, t, n-1 , m-1,dp);

            //look for another occurence of t[m-1] in reduced string s;
            int notPick = solve(s, t, n-1 , m,dp);

            return dp[n][m] = pick + notPick;
        }else {
            //look for another occurence of t[m-1] in reduced string s;
            return dp[n][m] = solve(s, t, n-1 , m,dp);
        }
    }
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(s, t, n , m, dp);
    }
};


//DP

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        vector<vector<unsigned long long int >>dp(n+1, vector<unsigned long long int >(m+1, 0));

        for(int i=0;i <= n;i++){
            for(int j=0;j <= m;j++){
                if(i == 0){
                    if(j == 0) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }else if(j == 0) dp[i][j] = 1;
                else{
                    if(s[i-1] == t[j-1]){
                        dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            } 
        }
        return dp[n][m];
    }
};