https://leetcode.com/problems/word-break/

class Solution {
public:
    bool solve(int ind, string s,unordered_set<string>&dist){
        if(ind == s.length()) return true;

        for(int i=ind;i < s.length();i++){
            if(dist.count(s.substr(ind, i-ind+1))){
                if(solve(i+1, s, dist))return true;
            }
        }

        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dist(wordDict.begin() , wordDict.end());
        return solve(0, s,dist);
    }
};

//Memoised

class Solution {
public:
    bool solve(int ind, string s,unordered_set<string>&dist,vector<int>&dp){
        if(ind == s.length()) return true;

        if(dp[ind] != -1) return dp[ind];

        for(int i=ind;i < s.length();i++){
            if(dist.count(s.substr(ind, i-ind+1))){
                if(solve(i+1, s, dist,dp))return true;
            }
        }

        return dp[ind] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n= s.length();
        unordered_set<string>dist(wordDict.begin() , wordDict.end());
        vector<int>dp(n+1, -1);
        return solve(0, s,dist,dp);
    }
};