https://leetcode.com/problems/arithmetic-slices/description/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n+1, 0);
        dp[0] = 0, dp[1] = 0;
        for(int i=2;i < n;i++){
            int diff = nums[i-1] - nums[i-2];
            if(diff == (nums[i] - nums[i-1])){
                dp[i] = dp[i-1] + 1; 
            }else dp[i] = 0;
        }

        int sum = 0;

        for(int i=0;i < n;i++) sum += dp[i];

        return sum;
    }
}; 