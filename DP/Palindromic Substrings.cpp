https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:

    bool isPalindrome(int start, int end, string &s){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    
    int countSubstrings(string s) {
        int count = 0;
        int n = s.length();

        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i=0;i < n;i++,count++) dp[i][i] = 1;

        for(int i=0;i < n-1;i++) {
            if(s[i] == s[i+1]){
                dp[i][i+1] = 1;
                count++;
            }
        }

        for(int len=3;len <= n;len++){
            for(int i=0,j=i+len-1;j < n;i++,j++){
                dp[i][j] = dp[i+1][j-1] && (s[i] == s[j]);
                count += dp[i][j];
            }
        }

        return count;
    }
};