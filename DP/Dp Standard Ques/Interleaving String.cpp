https://leetcode.com/problems/interleaving-string/description/


class Solution {
public:
    int n1, n2, n3;
    int solve(int i, int j, int k, string s1, string s2, string s3){
        if(k == s3.length()){
            if(j == s2.length() && i == s1.length()) return 1;
            else return 0;
        }
        
        int option1 = 0, option2 = 0;
        if(i < n1 && s1[i] == s3[k]) option1 = solve(i+1, j, k+1, s1, s2, s3);
        if(j < n2 && s2[j] == s3[k]) option2 = solve(i, j+1, k+1, s1, s2, s3);
        return option1 || option2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length(), n2 = s2.length() , n3 = s3.length();
        return solve(0, 0, 0, s1, s2, s3);
    }
};


// Method 1 O(n^3)
//Memoised

class Solution {
public:
    int n1, n2, n3;
    int solve(int i, int j, int k, string s1, string s2, string s3,vector<vector<vector<int>>>&dp){
        if(k == s3.length()){
            if(j == s2.length() && i == s1.length()) return 1;
            else return 0;
        }
        if(dp[i][j][k] != -1) return dp[i][j][k];

        int option1 = 0, option2 = 0;
        if(i < n1 && s1[i] == s3[k]) option1 = solve(i+1, j, k+1, s1, s2, s3,dp);
        if(j < n2 && s2[j] == s3[k]) option2 = solve(i, j+1, k+1, s1, s2, s3,dp);
        return dp[i][j][k] = option1 || option2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length(), n2 = s2.length() , n3 = s3.length();
        vector<vector<vector<int>>>dp(n1+1, vector<vector<int>>(n2+1, vector<int>(n3+1, -1)));
        return solve(0, 0, 0, s1, s2, s3, dp);
    }
};



// Method 2 O(n^2)
class Solution {
public:
    int n1, n2, n3;
    //k is redundant because k = i + j;
    int solve(int i, int j, string s1, string s2, string s3,vector<vector<int>>&dp){
        int k = i+j;
        if(k == s3.length()){
            if(j == s2.length() && i == s1.length()) return 1;
            else return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];

        int option1 = 0, option2 = 0;
        if(i < n1 && s1[i] == s3[k]) option1 = solve(i+1, j, s1, s2, s3,dp);
        if(j < n2 && s2[j] == s3[k]) option2 = solve(i, j+1, s1, s2, s3,dp);
        return dp[i][j] = option1 || option2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        n1 = s1.length(), n2 = s2.length() , n3 = s3.length();
        vector<vector<int>>dp(n1+1, vector<int>(n2+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};