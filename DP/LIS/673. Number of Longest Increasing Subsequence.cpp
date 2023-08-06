https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/

nums[]  : 1 5 4 3 2 6 7 10 8 9 
length[]: 1 2 2 2 2 3 4 5 5 6 
count[] : 1 1 1 1 1 4 4 4 4 4

here array nums is given
length[i] will give LIS length ending at index i
count[i] will give no. of LIS of length length[i] ending at index i

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int>dp(n, 1), cnt(n , 1);

        int maxi = 1;
        for(int i=0;i < n;i++){
            for(int prev=0;prev < i;prev++){
                if(nums[i] > nums[prev]){
                    if(dp[i] < dp[prev] + 1){
                        dp[i] = dp[prev] + 1;
                        cnt[i] = cnt[prev];
                    }else if(dp[i] == dp[prev] + 1){
                        cnt[i] += cnt[prev];
                    }
                }
            } 
            maxi = max(dp[i], maxi);
        }

        int ans = 0;
        for(int i=0;i < n;i++){
           if(dp[i] == maxi)  ans += cnt[i];
        }

        return ans;
    }
};