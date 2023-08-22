https://leetcode.com/problems/minimum-size-subarray-sum/description/

//Sliding window

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0;
        int n = nums.size();
        int sum = 0;
        int len = INT_MAX;

        while(right < n){
            sum += nums[right];
            while(sum > target){
                if(sum - nums[left] >= target){
                    sum -= nums[left];
                    left++;
                }else break;
            }

            if(sum >= target){
                len = min(len , right - left  + 1);
            }

            right++;
        }

        if(len != INT_MAX) return len;
        else return 0;
    }
};