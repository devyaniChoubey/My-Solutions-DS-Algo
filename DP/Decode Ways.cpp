https://leetcode.com/problems/decode-ways/?envType=company&envId=google&favoriteSlug=google-thirty-days&status=TO_DO

class Solution {
public:
    int solve(int ind, string s,vector<int>&dp){
        if(ind >= s.length()) return 1;

        if(dp[ind] != -1) return dp[ind];

        int ways = 0;

        if(s[ind] != '0'){
            ways += solve(ind+1, s,dp);
        } 

        if(stoi(s.substr(ind, 2)) >= 10 && stoi(s.substr(ind, 2)) <= 26){
            ways += solve(ind+2, s,dp);
        }
        
        return dp[ind] = ways;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length() , -1);
        return solve(0, s,dp);
    }
};