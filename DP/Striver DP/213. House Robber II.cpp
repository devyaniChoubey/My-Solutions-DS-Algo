https://leetcode.com/problems/house-robber-ii/description/

class Solution {
public:
    int solve(vector<int>& nums){
        int n = nums.size();
        vector<int>dp(n+1, 0);
        for(int i=n;i >= 0;i--){
            if(i == n) dp[i] = 0;
            else{
                int pick = nums[i];
                if(i < n-1) pick += dp[i+2];
                int notPick = dp[i+1];
                dp[i] = max(pick, notPick);
            }
        }
        return dp[0];
    }
    int rob(vector<int>& nums) {
        vector<int>temp1, temp2;
        int n = nums.size();

        if(n == 1) return nums[0];

        for(int i=0;i < n;i++){
           if(i != 0) temp1.push_back(nums[i]);
           if(i != n-1) temp2.push_back(nums[i]);
        }

        return max(solve(temp1) , solve(temp2));
    }
};