
https://leetcode.com/problems/binary-subarrays-with-sum/description/

class Solution {
public:
    int numSubarraysWithAtMostSum(vector<int>& nums, int goal){
        int right = 0, left = 0;

        if(goal < 0) return 0;

        int n = nums.size();
        int sum = 0;

        int ans = 0;

        while(right < n){
            sum += nums[right];

            while(sum > goal){
                sum -= nums[left];
                left++;
            }

            ans += right - left + 1;

            right++;
        }

        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return numSubarraysWithAtMostSum(nums, goal) - numSubarraysWithAtMostSum(nums, goal-1);
    }
};