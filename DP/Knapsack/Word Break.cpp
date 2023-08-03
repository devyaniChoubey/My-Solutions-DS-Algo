https://leetcode.com/problems/word-break/description/

class Solution {
public:
    unordered_set<string>wordList;
    bool solve(int pos, string s){
        int n = s.length();
        if(pos >= n) return true;

        for(int i=pos;i < n;i++){
            if(wordList.count(s.substr(pos, i-pos+1)) && solve(i+1, s)){
                return true;
            }
        }

        return false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict) wordList.insert(it);

        return solve(0, s);
    }
};


//Memoised

class Solution {
public:
    unordered_set<string>wordList;
    bool solve(int pos, string s, vector<int>&dp){
        int n = s.length();
        if(pos >= n) return true;

        if(dp[pos] != -1) return dp[pos];

        for(int i=pos;i < n;i++){

            if(wordList.count(s.substr(pos, i-pos+1)) && solve(i+1, s,dp)){
                return dp[pos] = true;
            }
        }

        return dp[pos] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict) wordList.insert(it);
        int n = s.length();
        vector<int>dp(n+1, -1);
        return solve(0, s,dp);
    }
};