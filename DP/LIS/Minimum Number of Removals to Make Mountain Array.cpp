//Calculate the longest bitonic sequence in the array and subtract this from total length of array.

https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), dpb(n, 1);
        for(int ind=0;ind < n;ind++){
            for(int prev=0;prev < ind;prev++){
                if(nums[ind] > nums[prev] && dp[ind] < dp[prev] + 1){
                   dp[ind] = dp[prev] + 1;
                }
            }
        }

        for(int ind=n-1;ind >= 0;ind--){
            for(int prev=n-1;prev > ind;prev--){
                if(nums[ind] > nums[prev] && dpb[ind] < dpb[prev] + 1){
                   dpb[ind] = dpb[prev] + 1;
                }
            }
        }

        int maxi = 0;
        
        for(int ind=1;ind < n-1;ind++){
            if(dp[ind] > 1 && dpb[ind] > 1){
                maxi = max(maxi, dp[ind] + dpb[ind] - 1);
            }
        }

        return n - maxi;
         
    }
};