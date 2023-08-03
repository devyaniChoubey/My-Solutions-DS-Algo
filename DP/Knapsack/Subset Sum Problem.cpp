https://practice.geeksforgeeks.org/problems/subset-sum-problem-1611555638/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


//Recursive
class Solution{   
public:
    bool solve(int n, vector<int>&arr, int sum){
        if(sum == 0) return true;
        if(n == 0) return false;
        
        bool take = false;
        if(arr[n-1] <= sum) take = solve(n-1, arr, sum-arr[n-1]);
        
        bool notTake = solve(n-1, arr, sum);
        
        return (take || notTake);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        return solve(n, arr, sum);
    }
};


//Memoised

class Solution{   
public:
    bool solve(int n, vector<int>&arr, int sum,vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(n == 0) return false;
        
        bool take = false;
        if(dp[n][sum] != -1) return dp[n][sum];
        if(arr[n-1] <= sum) take = solve(n-1, arr, sum-arr[n-1],dp);
        
        bool notTake = solve(n-1, arr, sum,dp);
        
        return dp[n][sum] = (take || notTake);
    }
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, -1));
        return solve(n, arr, sum, dp);
    }
};


//DP

class Solution{   
public:
    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        dp[0][0] = 1;
        for(int i=1;i <= n;i++){
            for(int j=0;j <= sum;j++){
                if(j == 0) dp[i][j] = 1;
                else{
                    int take = 0;
                    if(arr[i-1] <= j) take = dp[i-1][j-arr[i-1]];
                    
                    int notTake = dp[i-1][j];
                    
                    dp[i][j] = (take || notTake);
                }
            }
        }
        return dp[n][sum];
    }
};
