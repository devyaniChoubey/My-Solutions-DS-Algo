https://practice.geeksforgeeks.org/problems/number-of-coins1824/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab


//Recursive
class Solution {
    public:
	int solve(int n, int sum, int coins[]){
	    
	    if(sum == 0) return 0;
	    else if(n == 0) return 1e9;
	    
	    int take = 1e9;
	    if(coins[n-1] <= sum){
	        take = 1 + solve(n, sum-coins[n-1], coins);
	    }
	    int notTake = solve(n - 1, sum, coins);
	    
	    return min(take, notTake);
	}
	int minCoins(int coins[], int M, int V) 
	{ 
        int ans = solve(M, V, coins);
        
        if(ans == 1e9) return -1;
        else return ans;
	} 
}



//Memoised

class Solution {
    public:
	int solve(int n, int sum, int coins[],vector<vector<int>>&dp){
	    
	    if(sum == 0) return 0;
	    else if(n == 0) return 1e9;
	    
	    if(dp[n][sum] != -1) return dp[n][sum];
	    
	    int take = 1e9;
	    if(coins[n-1] <= sum){
	        take = 1 + solve(n, sum-coins[n-1], coins,dp);
	    }
	    int notTake = solve(n - 1, sum, coins,dp);
	    
	    return dp[n][sum] = min(take, notTake);
	}
	int minCoins(int coins[], int M, int V) 
	{   
	    vector<vector<int>>dp(M+1, vector<int>(V+1, -1));
        int ans = solve(M, V, coins, dp);
        
        if(ans == 1e9) return -1;
        else return ans;
	} 
}