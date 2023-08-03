https://practice.geeksforgeeks.org/problems/minimum-sum-partition3317/1

class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sum = 0;
	    sum = accumulate(arr, arr+n, sum);
	    int totalSum = sum;
	    
	    sum = sum/2;
	    
	    vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
	    
	    dp[0][0] = 1;
	    for(int i=1;i <= n;i++){
	        for(int j=0;j <= sum;j++){
	           if(j == 0) dp[i][j] = 1;
	           else{
	               int take = 0;
	               if(arr[i-1] <= j) take = dp[i-1][j-arr[i-1]];
	               int notTake = dp[i-1][j];
	               
	               dp[i][j] = take || notTake;
	           }
	        }
	    }
	    
	    int ans = 1e9;
	    
	    for(int j=0;j <= sum; j++){
	        if(dp[n][j] == 1){
	            ans = min(ans, abs(totalSum - 2*j));
	        }
	    }
	    
	    return ans;
	} 
};
