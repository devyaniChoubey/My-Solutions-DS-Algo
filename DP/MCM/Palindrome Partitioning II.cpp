https://leetcode.com/problems/palindrome-partitioning-ii/description/


//Recursive
class Solution {
public:
    bool isPalindrome(int start, int end,string s){
        while(start < end){
            if(s[start] != s[end])return false;
            start++;end--;
        }
        return true;
    }

    int solve(int i, string s){
        if(i == s.size()) return 0;
        
        int minVal = 1e9;
        for(int k=i;k < s.size();k++){
            if(isPalindrome(i, k,s)){
                minVal = min(minVal , 1 + solve(k+1, s));
            }
        }
        return minVal;
    }
    int minCut(string s) {
        return solve(0, s) - 1;
    }
};


//Memoised
class Solution {
public:
    bool isPalindrome(int start, int end,string s){
        while(start < end){
            if(s[start] != s[end])return false;
            start++;end--;
        }
        return true;
    }

    int solve(int i, string &s,vector<int>&dp){
        if(i == s.size()) return 0;
        
        if(dp[i] != -1) return dp[i];
        int minVal = 1e9;
        for(int j=i;j < s.size();j++){
            if(isPalindrome(i, j,s)){
                minVal = min(minVal , 1 + solve(j+1, s,dp));
            }
        }
        return dp[i] = minVal;
    }
    int minCut(string s) {
        int n = s.length();
        vector<int>dp(n+1, -1);
        return solve(0, s, dp) - 1;
    }
};



//DP

class Solution {
public:
    bool isPalindrome(int start, int end,string &s){
        while(start < end){
            if(s[start] != s[end])return false;
            start++;end--;
        }
        return true;
    }

    int minCut(string &str) {
        int n = str.size();
        vector<int>dp(n+1, 0);
        for(int i=n;i >= 0;i--){
            if(i == n) dp[i] = 0;
            else{
                int mini = 1e9;
                for(int k=i;k < n;k++){
                    if(isPalindrome(i, k, str)){
                        int minVal = 1 + dp[k+1];
                        mini = min(mini, minVal);
                    }
                }
                dp[i] = mini;
            }
        }
        return dp[0] - 1;
    }
};
