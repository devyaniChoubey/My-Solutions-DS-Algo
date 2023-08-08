https://leetcode.com/problems/regular-expression-matching/


//Recursive
class Solution {
public:
    bool solve(int i, int j , string s, string p){
        if(i == 0 && j == 0) return true;
        if(i != 0 && j == 0) return false;
        if(i == 0 && j != 0){
            if (p[j-1] == '*') {
                return solve(i, j - 2,s, p);
            } else {
                return false;
            }
        }

        if(s[i-1] == p[j-1] || (p[j-1] == '.')){
            return solve(i-1, j-1, s , p);
        }else if(p[j-1] == '*'){
            if((p[j-2] == '.') || (p[j-2] == s[i-1])){
                return solve(i-1, j, s , p) || solve(i, j-2, s , p);
            }
            return solve(i, j-2, s , p);
        }else{
           return 0;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length() , m = p.length();
        return solve(n, m, s , p);
    }
};


//Memoised

class Solution {
public:
    int solve(int i, int j , string s, string p, vector<vector<int>>&dp){
        if(i == 0 && j == 0) return 1;
        if(i != 0 && j == 0) return 0;
        if(i == 0 && j != 0){
            if (p[j-1] == '*') {
                return dp[i][j] = solve(i, j - 2,s, p,dp);
            } else {
                return 0;
            }
        }

        if(s[i-1] == p[j-1] || (p[j-1] == '.')){
            return dp[i][j] = solve(i-1, j-1, s , p,dp);
        }else if(p[j-1] == '*'){
            if((p[j-2] == '.') || (p[j-2] == s[i-1])){
                return dp[i][j] = solve(i-1, j, s , p, dp) || solve(i, j-2, s , p, dp);
            }
            return dp[i][j] = solve(i, j-2, s , p, dp);
        }else{
           return 0;
        }
    }
    bool isMatch(string s, string p) {
        int n = s.length() , m = p.length();
        vector<vector<int>>dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, s , p, dp);
    }
};