https://practice.geeksforgeeks.org/problems/gold-mine-problem2608/1

//REcursive
class Solution{
public:
    int solve(int i, int j, vector<vector<int>>gold){
        int m = gold[0].size();
        int n = gold.size();
        if(j == m-1) return gold[i][j];
        
        int upDiag = -1e9, right = -1e9, lowerDiag = -1e9;
        if(i > 0)upDiag = solve(i-1, j+1, gold);
        right = solve(i, j+1, gold);
        if(i < n-1)lowerDiag = solve(i+1, j+1, gold);
        
        return gold[i][j] + max(upDiag, max(right, lowerDiag));
        
        
    }
    int maxGold(int n, int m, vector<vector<int>>gold)
    {
        // code here
        
        int ans = -1e9;
        
        for(int i=0;i < n;i++){
            ans = max(ans, solve(i, 0, gold));
        }
        return ans;
    }
};


//Memoised
class Solution{
public:
    int solve(int i, int j, vector<vector<int>>gold,vector<vector<int>>&dp){
        int m = gold[0].size();
        int n = gold.size();
        if(j == m-1) return gold[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int upDiag = -1e9, right = -1e9, lowerDiag = -1e9;
        if(i > 0)upDiag = solve(i-1, j+1, gold,dp);
        right = solve(i, j+1, gold,dp);
        if(i < n-1)lowerDiag = solve(i+1, j+1, gold,dp);
        
        return dp[i][j] = gold[i][j] + max(upDiag, max(right, lowerDiag));
        
        
    }
    int maxGold(int n, int m, vector<vector<int>>gold)
    {
        // code here
        
        int ans = -1e9;
        vector<vector<int>>dp(n, vector<int>(m, -1));
        
        for(int i=0;i < n;i++){
            ans = max(ans, solve(i, 0, gold, dp));
        }
        return ans;
    }
};


//DP
class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>>gold)
    {
        // code here
        
        int ans = -1e9;
        vector<vector<int>>dp(n, vector<int>(m, 0));
        
        for(int j=m-1;j >= 0;j--){
            for(int i=0;i < n;i++){
                if(j == m-1) dp[i][j] = gold[i][j];
                else{
                    int upDiag = -1e9, lowerDiag = -1e9, right = -1e9;
                    
                    if(i < n-1) lowerDiag = dp[i+1][j+1];
                    if(i > 0) upDiag = dp[i-1][j+1];
                    right = dp[i][j+1];
                    
                    dp[i][j] = gold[i][j] + max(lowerDiag, max(right, upDiag));
                }
            }
        }
        
        for(int i=0;i < n;i++){
            ans = max(ans, dp[i][0]);
        }
        return ans;
    }
};