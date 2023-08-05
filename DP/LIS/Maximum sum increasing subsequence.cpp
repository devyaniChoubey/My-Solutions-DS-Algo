https://practice.geeksforgeeks.org/problems/maximum-sum-increasing-subsequence4749/1?utm_source=geeksforgeeks&utm_medium=article_practice_tab&utm_campaign=article_practice_tab

//Recursive

class Solution{
	public:
	int solve(int ind, int prevIndex, int nums[], int n){
	    if(ind >= n) return 0;
	    
	    int pick = -1;
	    if((prevIndex == -1) || (nums[ind] > nums[prevIndex])) pick = nums[ind] + solve(ind+1, ind,nums, n);
	    
	    int notPick = solve(ind+1, prevIndex, nums, n);
	    
	    return max(pick, notPick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    return solve(0, -1, arr, n);
	    
	}  
};



//Memoised

class Solution{
	public:
	int solve(int ind, int prevIndex, int nums[], int n,vector<vector<int>>&dp){
	    if(ind >= n) return 0;
	    
	    int pick = -1;
	    if(dp[ind][prevIndex + 1] != -1) return dp[ind][prevIndex + 1];
	    
	    if((prevIndex == -1) || (nums[ind] > nums[prevIndex])) pick = nums[ind] + solve(ind+1, ind,nums, n,dp);
	    
	    int notPick = solve(ind+1, prevIndex, nums, n,dp);
	    
	    return dp[ind][prevIndex + 1] = max(pick, notPick);
	}
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>>dp(n+1, vector<int>(n+2, -1));
	    return solve(0, -1, arr, n, dp);
	}  
};