https://practice.geeksforgeeks.org/problems/51b266505221b97522b1d2c86ddad1868a54831b/1?utm_source=geeksforgeeks&utm_medium=ml_article_practice_tab&utm_campaign=article_practice_tab

//recursive

class Solution{   
public:
    int solve(int i, int j, vector<vector<int>> &colors, int n){
        if(i == n-1) return colors[i][j];
        
        int mini = 1e9;
        for(int j1=0;j1 < 3;j1++){
            if(j1 == j) continue;
            mini = min(mini, colors[i][j] + solve(i+1, j1, colors, n));
        }
        
        return mini;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int ans = 1e9;
        for(int j=0;j < 3;j++){
            ans = min(ans, solve(0, j, colors, N));
        }
        return ans;
    }
};



//Memoised

class Solution{   
public:
    int solve(int i, int j, vector<vector<int>> &colors,vector<vector<int>> &dp, int n){
        if(i == n-1) return colors[i][j];
        
        if(dp[i][j] != -1) return dp[i][j];
        int mini = 1e9;
        for(int j1=0;j1 < 3;j1++){
            if(j1 == j) continue;
            mini = min(mini, colors[i][j] + solve(i+1, j1, colors,dp, n));
        }
        
        return dp[i][j] = mini;
    }
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int ans = 1e9;
        vector<vector<int>>dp(N , vector<int>(3, -1));
        for(int j=0;j < 3;j++){
            ans = min(ans, solve(0, j, colors,dp, N));
        }
        return ans;
    }
};


//DP

//User function Template for C++

class Solution{   
public:
    int minCost(vector<vector<int>> &colors, int N) {
        // Write your code here.
        int ans = 1e9;
        vector<vector<int>>dp(N , vector<int>(3, 0));
        for(int i=N-1;i >= 0;i--){
           for(int j=0;j < 3;j++){
               if(i == N-1) dp[i][j] = colors[i][j];
               else{
                   int mini = 1e9;
                   for(int j1=0;j1 < 3;j1++){
                       if(j == j1) continue;
                       mini = min(mini, colors[i][j] + dp[i+1][j1]);
                   }
                   dp[i][j] = mini;
               }
           } 
        }
        for(int j=0;j < 3;j++){
            ans = min(ans, dp[0][j]);
        }
        return ans;
    }
};