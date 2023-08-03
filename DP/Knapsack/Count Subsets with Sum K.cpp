https://www.codingninjas.com/studio/problems/count-subsets-with-sum-k_3952532?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf


//Recursive
int solve(int n , vector<int>& nums, int target){
  if(target == 0 && n == 0) return 1;
  if(n == 0) return 0;
  
  int take = 0;
  if(nums[n-1] <= target) take = solve(n-1, nums, target - nums[n-1]);
  
  int notTake = solve(n-1, nums, target);
  
  return take + notTake;
}

int findWays(vector<int>& nums, int target)
{
	// Write your code here.
  int n = nums.size();
  return solve(n, nums, target);
}






//Memoised

int solve(int n , vector<int>& nums, int target,vector<vector<int>>&dp){
  if(target == 0 && n == 0) return 1;
  if(n == 0) return 0;
  
  if(dp[n][target] != -1) return dp[n][target];
  int take = 0;
  if(nums[n-1] <= target) take = solve(n-1, nums, target - nums[n-1],dp);
  
  int notTake = solve(n-1, nums, target,dp);
  
  return dp[n][target] = take + notTake;
}

int findWays(vector<int>& nums, int target)
{
	// Write your code here.
  int n = nums.size();
  vector<vector<int>>dp(n+1, vector<int>(target+1, -1));
  return solve(n, nums, target, dp);
}


//DP

int findWays(vector<int>& nums, int target)
{
  int mod = (1e9+7);
	// Write your code here.
  int n = nums.size();
  vector<vector<int>>dp(n+1, vector<int>(target+1, 0));
  for(int i=0;i <= n;i++){
    for(int j=0;j <= target;j++){
      if(i==0 && j==0) dp[i][j] = 1;
      else if(i==0)dp[i][j] = 0;
      else {
        int take = 0;
        if(nums[i-1] <= j) take = dp[i-1][j-nums[i-1]];
        int notTake = dp[i-1][j];
        
        dp[i][j] = (take + notTake)%mod;
      }
    }
  }
  
  return dp[n][target]%mod;
}
