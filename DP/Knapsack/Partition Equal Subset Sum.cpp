https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool solve(int n, int sum, vector<int>& nums){
        if(sum == 0) return true;
        if(n == 0) return false;

        int take = 0;
        if(nums[n-1] <= sum) take = solve(n-1, sum - nums[n-1], nums);

        int notTake = solve(n-1, sum, nums);

        return (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), sum);
        if(sum % 2 != 0) return false;

        return solve(n, sum/2, nums);
    }
};


//Memoisation

class Solution {
public:
    bool solve(int n, int sum, vector<int>& nums,vector<vector<int>>&dp){
        if(sum == 0) return true;
        if(n == 0) return false;

        if(dp[n][sum] != -1) return dp[n][sum];
        int take = 0;
        if(nums[n-1] <= sum) take = solve(n-1, sum - nums[n-1], nums,dp);

        int notTake = solve(n-1, sum, nums,dp);

        return dp[n][sum] = (take || notTake);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        sum = accumulate(nums.begin(), nums.end(), sum);
        if(sum % 2 != 0) return false;

        vector<vector<int>>dp(n+1, vector<int>(sum/2 + 1, -1));
        return solve(n, sum/2, nums, dp);
    }
};