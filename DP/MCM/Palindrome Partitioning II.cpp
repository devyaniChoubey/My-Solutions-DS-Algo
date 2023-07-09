class Solution {
public:
    bool isPalindrome(int start, int end,string s){
       // int start = 0, end = s.length() - 1;

        while(start < end){
            if(s[start] != s[end])return false;
            start++;end--;
        }

        return true;
    }
    int solve(int i, string s){
        if(i == s.size()) return 0;
        
        int minVal = 1e9;
        for(int j=i;j < s.size();j++){
            if(isPalindrome(i, j,s)){
                minVal = min(minVal , 1 + solve(j+1, s));
            }
        }
        return minVal;
    }
    int minCut(string s) {
        return solve(0, s) - 1;
    }
};



class Solution {
public:
    bool isPalindrome(int start, int end,string s){
       // int start = 0, end = s.length() - 1;

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