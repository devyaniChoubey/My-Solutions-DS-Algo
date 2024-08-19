https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int solve(int target, vector<int>& nums,vector<int>&dp){
        if(target == 0) return 1;
        else if(target < 0) return 0;

        if(dp[target] != -1) return dp[target];
        
        int cnt = 0;
        for(int i=0;i < nums.size();i++){
            if(target < nums[i]) continue;
            cnt += solve(target-nums[i], nums,dp);
        }

        return dp[target] = cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        vector<int>dp(target+1, -1);
        return solve(target, nums,dp);
    }
};

