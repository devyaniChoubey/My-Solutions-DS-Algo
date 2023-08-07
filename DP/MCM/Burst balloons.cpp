https://leetcode.com/problems/burst-balloons/description/


start recursion from the last balloon left
//Recursive
class Solution {
public:
    int solve(int i, int j, vector<int>& nums){
        if(i > j) return 0;

        int maxi = -1e9;
        for(int k=i;k <= j;k++){
            int totalCost = solve(i, k-1, nums) + nums[i-1]*nums[k]*nums[j+1] + solve(k+1, j, nums);
            maxi = max(maxi, totalCost);
        }

        return maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        return solve(1, n-2, nums);
    }
};



//Memoisation
class Solution {
public:
    int solve(int i, int j, vector<int>& nums,vector<vector<int>>&dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];
        int maxi = -1e9;
        for(int k=i;k <= j;k++){
            int totalCost = solve(i, k-1, nums,dp) + nums[i-1]*nums[k]*nums[j+1] + solve(k+1, j, nums,dp);
            maxi = max(maxi, totalCost);
        }

        return dp[i][j] = maxi;
    }
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        int n = nums.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));

        return solve(1, n-2, nums,dp);
    }
};


//Tabulation

class Solution {
public:
  
    int maxCoins(vector<int>& nums) {
        nums.push_back(1);
        nums.insert(nums.begin(), 1);
        int n = nums.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));

        for(int i=n-2;i >= 1;i--){
            for(int j=i;j <= n-2;j++){
                int maxi = -1e9;
                for(int k=i;k <=j;k++){
                    int val = dp[i][k-1] + dp[k+1][j] + nums[i-1]*nums[k]*nums[j+1];
                    maxi = max(maxi, val);
                }
                dp[i][j] = maxi;
            }
        }

        return dp[1][n-2];
    }
};



