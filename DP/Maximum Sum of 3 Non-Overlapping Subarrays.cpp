https://leetcode.com/problems/maximum-sum-of-3-non-overlapping-subarrays/


class Solution {
public:
    int solve(int ind,int subArrayCnt, vector<int>&windowSum,int k,vector<vector<int>>&dp){
        int n = windowSum.size();

        if(subArrayCnt == 0) return 0;
        if(ind >= n) return -1e9;

        if(dp[ind][subArrayCnt] != -1) return dp[ind][subArrayCnt];

        int pick = windowSum[ind] + solve(ind+k,subArrayCnt-1, windowSum,k,dp);
        int notPick = solve(ind+1,subArrayCnt, windowSum,k,dp);

        return dp[ind][subArrayCnt] = max(pick, notPick);
    }

    void dfs(int ind,int subArrayCnt, vector<int>&windowSum,int k,vector<vector<int>>&dp,vector<int>&indices){
        if(ind >= windowSum.size() || subArrayCnt == 0) return;
        int withCurrent = windowSum[ind] + solve(ind+k,subArrayCnt-1, windowSum,k,dp);
        int withoutCurrent = solve(ind+1,subArrayCnt, windowSum,k,dp);

        if(withCurrent >= withoutCurrent){
            indices.push_back(ind);
            dfs(ind+k,subArrayCnt-1, windowSum,k,dp, indices);
        }else{
            dfs(ind+1,subArrayCnt, windowSum,k,dp, indices);
        }

    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int curSum = 0;

        for(int i=0;i < min(k, n);i++){
            curSum += nums[i];
        }

        vector<int>ans;

        vector<int>windowSum(n-k+1, 0);
        windowSum[0] = curSum;

        for(int i=1;i <= n-k;i++){
            curSum -= nums[i-1];
            curSum += nums[i+k-1];
            windowSum[i] = curSum;
        }

        vector<vector<int>>dp(n+1, vector<int>(4, -1));

        solve(0,3, windowSum,k,dp);

        vector<int>indices;

        dfs(0, 3, windowSum, k, dp, indices);

        return indices;
    }
};