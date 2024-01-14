https://practice.geeksforgeeks.org/problems/partitions-with-given-difference/1

class Solution {
  public:
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        int sum = 0;
        int mod = 1e9+7;
        sum = accumulate(arr.begin(), arr.end(), sum);
        
        if((d+sum)% 2 != 0 || (d-sum)%2 != 0) return 0;
        
        sum = (d+sum)/2;
        
        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        
        for(int i=0;i <= n;i++){
            for(int j=0;j <= sum;j++){
                if(i == 0){
                    if(j == 0) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }else{
                    int take = 0;
                    if(arr[i-1] <= j) take = dp[i-1][j-arr[i-1]];
                    int notTake = dp[i-1][j];
                    
                    dp[i][j] = (take + notTake)%mod;
                
            }
        }
        
        return (dp[n][sum])%mod;
    }
};