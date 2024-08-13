https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int cnt0 = 0, n = nums.size() , left = 0, right = 0, ans = 0;

        while(right < n){
            cnt0 += (1 - nums[right]);

            if(cnt0 > 1){
                cnt0 -= (1 - nums[left]);
                left++;
            }

            ans = max(ans, right - left);
            right++;
        }

        return ans;
    }
};