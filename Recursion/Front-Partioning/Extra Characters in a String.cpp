https://leetcode.com/problems/extra-characters-in-a-string/?envType=daily-question&envId=2024-09-23

class Solution {
public:
    int solve(int ind, string &s, unordered_set<string>&dict,vector<int>&dp){
        if(ind == s.length())return 0;

        if(dp[ind] != -1) return dp[ind];

        int ans = 1e9;
        for(int i=ind;i < s.length();i++){
            if(dict.count(s.substr(ind, i-ind+1))){
                ans = min(ans, solve(i+1, s, dict,dp));
            }else {
                ans = min(ans, i-ind+1+solve(i+1, s, dict,dp));
            }
        }
        return dp[ind] = ans;
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_set<string>dict(dictionary.begin(), dictionary.end());
        vector<int>dp(s.length() + 1, -1);
        return solve(0, s, dict,dp);
    }
};