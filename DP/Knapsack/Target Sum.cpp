https://leetcode.com/problems/target-sum/description/

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), sum);

        if((target+sum) % 2 != 0 || (sum-target) % 2 != 0) return 0;

        if(target > sum || abs(target) > sum) return 0;

        sum = (target+sum)/2;

        

        vector<vector<int>>dp(n+1, vector<int>(sum+1, 0));
        for(int i=0;i <= n;i++){
            for(int j=0;j <= sum;j++){
                if(i == 0){
                    if(j==0) dp[i][j] = 1;
                    else dp[i][j] = 0;
                }else{
                    int take = 0;
                    if(nums[i-1] <= j) take = dp[i-1][j-nums[i-1]];
                    int notTake = dp[i-1][j];

                    dp[i][j] = take + notTake;
                }
            }
        }

        return dp[n][sum];
    }
};